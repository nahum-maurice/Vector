// C++ program to implement Custom Vector
// class

#include<cmath>
#include <iostream>
#include <string>
#include <cassert>
#include <sstream>
#include <cmath>
#define PI 3.1415926535897932;

typedef size_t n;


// Template class to create Vector of
// different data_type
template <typename Vect>
class NVector {
private:
    Vect* vect;

    // Variable to store the current capacity
    // of the Vector
    n capacity;

    // Variable to store the length of the
    // Vector
    n length;

public:
    explicit NVector(n = 100);

    // Function that returns the number of
    // elements in vector after pushing the data
    n push_back(Vect);

    // function that returns the popped element
    Vect pop_back();

    // function that verify if a element is present
    bool is_present(Vect);

    // Function that return the length of Vector
    n size() const;
    Vect& operator[](n);


    // toString, magnitude, angle, orthogonal vector...
    std::string toString() const;

    Vect magnitude() const;
    Vect angleToAxis(const Vect nth_axe);
    Vect angle(NVector &otherVect);

    // Operation overloads
    NVector<Vect> operator + (const NVector &toAddVect);
    NVector<Vect> operator - (const NVector &toSubstractVect);
    NVector<Vect> operator * (const NVector<Vect> &toMultiplyVect);
    NVector<Vect> operator = (const NVector<Vect> &toAssignVect);

    // Iterator Class
    class iterator {
    private:
        // Dynamic vectay using poners
        Vect* ptr;

    public:
        explicit iterator()
                : ptr(nullptr)
        {
        }
        explicit iterator(Vect* p)
                : ptr(p)
        {
        }
        bool operator==(const iterator& rhs) const
        {
            return ptr == rhs.ptr;
        }
        bool operator!=(const iterator& rhs) const
        {
            return !(*this == rhs);
        }
        Vect operator*() const
        {
            return *ptr;
        }
        iterator& operator++()
        {
            ++ptr;
            return *this;
        }
        iterator operator++(int)
        {
            iterator temp(*this);
            ++*this;
            return temp;
        }
    };

    // Begin iterator
    iterator begin() const;

    // End iterator
    iterator end() const;
};

// Template class to return the length of
// Vector of different data_type
template <typename Vect>
NVector<Vect>::NVector(n n)
        : capacity(n), vect(new Vect[n]), length(0)
{
}

// Template class to insert the element
// in Vector
template <typename Vect>
n NVector<Vect>::push_back(Vect data)
{
    if (length == capacity) {
        Vect* old = vect;
        vect = new Vect[capacity = capacity * 2];
        //copy(old, old + length, vect);
        delete[] old;
    }
    vect[length++] = data;
    return length;
}

// Template class to return the popped element
// in Vector
template <typename Vect>
Vect NVector<Vect>::pop_back()
{
    return vect[length-- - 1];
}
// function that verify if a element is present
template <typename Vect>
bool NVector<Vect>::is_present(Vect data){
    for(n i =0; i < size(); i++) {
      if(vect[i] == data)
          return true;
      false;
    }
}
// Template class to return the length of
// Vector
template <typename Vect>
n NVector<Vect>::size() const
{
    return length;
}

// Template class to return the element of
// Vector at given index
template <typename Vect>
Vect& NVector<Vect>::operator[](n index)
{
    // if given index is greater than the
    // length of Vector prn Error
    if (index >= length) {
        std::cout << "Error: vectay index out of bound";
        exit(0);
    }

    // else return value at that index
    return *(vect + index);
}

// Template class to return begin iterator
template <typename Vect>
typename NVector<Vect>::iterator
NVector<Vect>::begin() const
{
    return iterator(vect);
}

// Template class to return end iterator
template <typename Vect>
typename NVector<Vect>::iterator
NVector<Vect>::end() const
{
    return iterator(vect + length);
}

// Template class to display element in
// Vector
template <typename V>
void display_Vector(V& v)
{
    // Declare iterator
    typename V::iterator ptr;
    for (ptr = v.begin(); ptr != v.end(); ptr++) {
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';
}


// Operation overloads
template <typename Vect>
NVector<Vect> NVector<Vect>::operator + (const NVector<Vect> &toAddVect){
    // Ensure that they are of the same length
    assert(length == toAddVect.length());
    NVector<Vect> temp(toAddVect.length());

    for (n i = 0; i < size(); i++) {
        temp.elems[i] = this->elems[i] + toAddVect.elems[i];
    }
    return temp;
};
template <typename Vect>
NVector<Vect> NVector<Vect>::operator - (const NVector<Vect> &toSubstractVect){
    // Ensure that they are of the same length
    assert(size() == toSubstractVect.length());

    NVector temp(toSubstractVect.length());
    for (n i = 0; i < size(); i++)
        temp.elems[i] = this->elems[i] - toSubstractVect.elems[i];
    return temp;
};
template <typename Vect>
NVector<Vect> NVector<Vect>::operator * (const NVector<Vect> &toMultiplyVect){
    // Ensure that they are of the same length
    assert(size() == toMultiplyVect.length());

    n sc_prod = 0;
    for (n i = 0; i < size(); i++)
        sc_prod += this ->vect[i] * toMultiplyVect.vect[i];
    return sc_prod;
};
template <typename Vect>
NVector<Vect> NVector<Vect>::operator = (const NVector<Vect>& toAssignVect){
    if (this != &toAssignVect){
        Vect *newElm = new Vect[toAssignVect.length()];
        // std::copy(toAssignVect.elems, toAssignVect.elems + toAssignVect.length(), newElm);
        for(n x=0; x < toAssignVect.length(); x++) {
            newElm[x] = toAssignVect.elems[x];
        };
        delete[] vect;
        this->length()= toAssignVect.length();
        this->vect = newElm;
    };
    return *this;
};
template <typename Vect>
std::string NVector<Vect>::toString() const {
    // Return closed empty brackets for empty vectors
    if (size() == 0) {return "[]";};

    std::stringstream stream;
    std::string stringOutput;
    for(int i=0; i < size(); i++) {
        stream << vect [i];
        if (i != size() -1)
            stream << ",";
    };
    stream >> stringOutput;
    stringOutput = "[" + stringOutput + "]";
    return stringOutput;
};
template <typename Vect>
Vect NVector<Vect>::magnitude() const {
    // Summarize the vector components : |a| = sqrt({x_a}^2 + ... + {x_n}^2)
    double norm = 0;
    for(n i=0; i<size(); i++) {
        norm += vect[i]*vect[i];
    };
    return std::sqrt(norm);
};
template <typename Vect>
Vect NVector<Vect>::angleToAxis(const Vect nth_axe) {
    // angle formula : arccos(nth_value_in_vect / norm) = arccos(projection_on_nth_axe / norm);
    Vect nth_value = vect[nth_axe - 1];
    std::cout << nth_value << std::endl;
    Vect norm = magnitude();
    double cos_angle = nth_value / norm;
    std::cout << cos_angle << std::endl;
    std::cout << norm << std::endl;
    double value = std::acos(cos_angle) * 180 / PI;
    return value;
};
template <typename Vect>
Vect NVector<Vect>::angle(NVector<Vect> &otherVect) {
    // angle formula : arccos(scalar_product / product of norms)
   if(length == otherVect.length);
    Vect sc_prod = 0;
    for (int i = 0; i < size(); i++)
        sc_prod += this ->vect[i] * otherVect.vect[i];
    // norms
    Vect norm_this = magnitude();
    Vect norm_other = otherVect.magnitude();

    Vect cos_angle = sc_prod / norm_this / norm_other;
    Vect value = std::acos(cos_angle) * 180 / PI;
    return value;
};



// Driver code
int main() {
    std::cout << "For integer data_type" << std::endl;

    NVector<int> v;
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);

    // Declare iterator for traversal in
    // Vector v
    NVector<n>::iterator it;

    // Function caned to display element in
    // Vector in v
    std::cout << "Element in Vector v : ";
    display_Vector(v);

    // Print the length of Vector v
   std:: cout << "length: " << v.size() << std::endl;

    // Print Element at index 2
    std::cout << "v[2]: " << v[2] << '\n';

    // Verify if element is in vector
    std::cout << std::boolalpha;
    std::cout << "element " << v[2] << " is in vector ? : " << v.is_present(v[2]) << '\n';


    // Pop an element and prn it
   std:: cout << "Popped Element: " << v.pop_back() << '\n';
    display_Vector(v);

    std::cout << std::endl;

    std::cout << "For Char data_type" << std::endl;

    NVector<char> c;
    c.push_back('a');
    c.push_back('b');
    c.push_back('c');
    c.push_back('d');
    c.push_back('e');
    c.push_back('f');
    c.push_back('g');
    c.push_back('h');

    // Declare iterator for traversal in
    // Vector c
    NVector<char>::iterator it1;

    // Function caned to display element in
    // Vector in c
    std::cout << "Element in Vector c : ";
    display_Vector(c);

    // Print the length of Vector c
    std::cout << "length: " << c.size() << '\n';

    // Prn Element at index 2
   std:: cout << "c[2]: " << c[2] << '\n';

    // Pop an element and prn it
    std::cout << "pop: " << c.pop_back() << '\n';

    // Function caned to display element in
    // Vector in c
   std:: cout << "Element in Vector c : ";
    display_Vector(c);

// magnitude, angleToAxis, angle
    double magnit = v.magnitude();
    double angleToY = v.angleToAxis(2); // Assuming that 2 is the y-axis
    NVector<int> other_vec;
    other_vec.push_back(3);
    other_vec.push_back(2);
    other_vec.push_back(4);
    other_vec.push_back(8);
    other_vec.push_back(4);
    other_vec.push_back(10);
    other_vec.push_back(11);
    other_vec.push_back(12);

    int angle = v.angle(other_vec);

    std::cout << "New values of vec: ";
    display_Vector(v);
    std::cout << "Magnitude of vec: " << magnit << std::endl;
    std::cout << "Angle to the y-axis of vec: " << angleToY << std::endl;
    std::cout << "New values of other_vec: ";
    display_Vector(other_vec);
    std::cout << "Angle between vec and other_vec: " << angle << std::endl;

    return 0;

}
