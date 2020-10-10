/*
Project 4 - Part 6 / 9
Video: Chapter 5 Part 3
 
Create a branch named Part6
 
 Lambdas
 
    Do not delete your previous main. you will be adding to it.

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 1) add two member functions named "apply()" to each of your Heap-Allocated Numeric Type wrappers.
         both apply() functions should work with chaining
 
 2) One of the apply() functions should takes a std::function<> object as the function argument.
    the std::function<> object should return *this;
 
 3) the other apply() function should take a function pointer. 
    the function pointer should return void.
 
 4) Make both of the member functions's Callable Function Parameter use your owned object as it's single parameter.
         e.g. if you manage your owned object via std::unique_ptr<T>, you'd use this for your std::function argument:
             std::function< OwnedT&(std::unique_ptr<T>&)>
             
         if you managed your owned object via a raw pointer, you'd use this for your std::function argument:
             std::function<OwnedT&(T&)>    
 
 5) call that Callable Function Parameter in the apply() member function.
         be sure to practice safe std::function usage (make sure it's not a nullptr function being called)
 
 6) copy the part6() function below and paste it after part4()
 7) call part6() after part4() is called at the end of main().

 8) fill in the missing arguments in part6 such that you produce the expected output.

 9) Make your lambda & free function update the value of your held object
 
 
build/run to make sure you don't have any errors
 
 If you need to see an example, look at https://bitbucket.org/MatkatMusic/pfmcpptasks/src/master/Projects/Project4/Part6Example.cpp
 */

void part6()
{
    FloatType ft3(3.0f);
    DoubleType dt3(4.0);
    IntType it3(5);
    
    std::cout << "Calling FloatType::apply() using a lambda (adds 7.0f) and FloatType as return type:" << std::endl;
    std::cout << "ft3 before: " << ft3 << std::endl;
    ft3.apply( [](){} );
    std::cout << "ft3 after: " << ft3 << std::endl;
    std::cout << "Calling FloatType::apply() using a free function (adds 7.0f) and void as return type:" << std::endl;
    std::cout << "ft3 before: " << ft3 << std::endl;
    ft3.apply(myFloatFreeFunct);
    std::cout << "ft3 after: " << ft3 << std::endl;
    std::cout << "---------------------\n" << std::endl;

    std::cout << "Calling DoubleType::apply() using a lambda (adds 6.0) and DoubleType as return type:" << std::endl;
    std::cout << "dt3 before: " << dt3 << std::endl;
    dt3.apply( [](){} );
    std::cout << "dt3 after: " << dt3 << std::endl;
    std::cout << "Calling DoubleType::apply() using a free function (adds 6.0) and void as return type:" << std::endl;
    std::cout << "dt3 before: " << dt3 << std::endl;
    dt3.apply(myDoubleFreeFunct);
    std::cout << "dt3 after: " << dt3 << std::endl;
    std::cout << "---------------------\n" << std::endl;

    std::cout << "Calling IntType::apply() using a lambda (adds 5) and IntType as return type:" << std::endl;
    std::cout << "it3 before: " << it3 << std::endl;
    it3.apply( [](){} );
    std::cout << "it3 after: " << it3 << std::endl;
    std::cout << "Calling IntType::apply() using a free function (adds 5) and void as return type:" << std::endl;
    std::cout << "it3 before: " << it3 << std::endl;
    it3.apply(myIntFreeFunct);
    std::cout << "it3 after: " << it3 << std::endl;
    std::cout << "---------------------\n" << std::endl;    
}

/*
your program should generate the following output EXACTLY.
This includes the warnings.
The output should have zero warnings.



FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

The result of FloatType^3 divided by IntType is: 26.9136
The result of DoubleType times 3 plus IntType is : 67.3
The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: 711
An operation followed by attempts to divide by 0, which are ignored and warns user: 
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
505521
FloatType x IntType  =  13143546
(IntType + DoubleType + FloatType) x 24 = 315447336
Power tests with FloatType 
pow(ft1, floatExp) = 2^2 = 4
pow(ft1, itExp) = 4^2 = 16
pow(ft1, ftExp) = 16^2 = 256
pow(ft1, dtExp) = 256^2 = 65536
---------------------

Power tests with DoubleType 
pow(dt1, doubleExp) = 2^2 = 4
pow(dt1, itExp) = 4^2 = 16
pow(dt1, ftExp) = 16^2 = 256
pow(dt1, dtExp) = 256^2 = 65536
---------------------

Power tests with IntType 
pow(it1, intExp) = 2^2 = 4
pow(it1, itExp) = 4^2 = 16
pow(it1, ftExp) = 16^2 = 256
pow(it1, dtExp) = 256^2 = 65536
===============================

Point tests with float argument:
Point { x: 3, y: 6 }
Multiplication factor: 6
Point { x: 18, y: 36 }
---------------------

Point tests with FloatType argument:
Point { x: 3, y: 3 }
Multiplication factor: 3
Point { x: 9, y: 9 }
---------------------

Point tests with DoubleType argument:
Point { x: 3, y: 4 }
Multiplication factor: 4
Point { x: 12, y: 16 }
---------------------

Point tests with IntType argument:
Point { x: 3, y: 4 }
Multiplication factor: 5
Point { x: 15, y: 20 }
---------------------

Calling FloatType::apply() using a lambda (adds 7.0f) and FloatType as return type:
ft3 before: 3
ft3 after: 10
Calling FloatType::apply() using a free function (adds 7.0f) and void as return type:
ft3 before: 10
ft3 after: 17
---------------------

Calling DoubleType::apply() using a lambda (adds 6.0) and DoubleType as return type:
dt3 before: 4
dt3 after: 10
Calling DoubleType::apply() using a free function (adds 6.0) and void as return type:
dt3 before: 10
dt3 after: 16
---------------------

Calling IntType::apply() using a lambda (adds 5) and IntType as return type:
it3 before: 5
it3 after: 10
Calling IntType::apply() using a free function (adds 5) and void as return type:
it3 before: 10
it3 after: 15
---------------------

good to go!

Use a service like https://www.diffchecker.com/diff to compare your output. 
*/


struct A {};

struct HeapA 
{
    HeapA() : a (new A())
    {

    }
    ~HeapA()
    {
        delete a;
        a = nullptr;
    }

    A* a;
};

 

#include <iostream>
#include <cmath>


struct IntType;
struct DoubleType;

struct FloatType
{
    FloatType (float val) : value (new float (val))
    {

    }
    ~FloatType ()
    {
        delete value;
        value = nullptr;
    }

    //float* value = nullptr; FIXME: 5) make your member variable private.


    FloatType& operator+=(float rhs);
    FloatType& operator-=(float rhs);
    FloatType& operator*=(float rhs);
    FloatType& operator/=(float rhs);

    operator float() const { return *value; }

    FloatType& pow(float ft);
    
    FloatType& pow(const FloatType& ft);
    FloatType& pow(const DoubleType& dt);
    FloatType& pow(const IntType& it);

    FloatType& apply (std::function<FloatType&(float&> func);
    FloatType& apply (void(*func)(float&));


    private:

    float* value = nullptr;
    FloatType& powInternal(const float f);

};

struct DoubleType
{
    DoubleType (double val) : value (new double(val)) 
    {

    }
    ~DoubleType ()
    {
        delete value;
        value = nullptr;
    }

    //double* value = nullptr; FIXME: 5) make your member variable private.

    DoubleType& operator+=(double rhs);
    DoubleType& operator-=(double rhs);
    DoubleType& operator*=(double rhs);
    DoubleType& operator/=(double rhs);

    operator double() const { return *value; }

    DoubleType& pow(double dt);

    DoubleType& pow(const FloatType& ft);
    DoubleType& pow(const DoubleType& dt);
    DoubleType& pow(const IntType& it);

    DoubleType& apply (std::function<DoubleType&(double&> func);
    DoubleType& apply (void(*func)(double&));

    private:
    double* value = nullptr;
    DoubleType& powInternal (const double pow);

};

struct IntType
{
    IntType (int val) : value (new int(val)) 
    {

    }
    ~IntType ()
    {
        delete value;
        value = nullptr;
    }

    //int* value = nullptr; FIXME: 5) make your member variable private.

    IntType& operator+=(int rhs);
    IntType& operator-=(int rhs);
    IntType& operator*=(int rhs);
    IntType& operator/=(int rhs);

    IntType& pow(int it);

    IntType& pow(const FloatType& ft);
    IntType& pow(const DoubleType& dt);
    IntType& pow(const IntType& it);

    IntType& apply(std::function<IntType&(int&> func);
    IntType& apply(void(*func)(int&));

    operator int() const { return *value; }

    private:
    int* value = nullptr;
    IntType& powInternal (const int pow);

};

struct Point
{
    Point (const FloatType& a, const FloatType& b) : x(static_cast<float>(a)),y(static_cast<float>(b)) {}

    Point (const DoubleType& a, const DoubleType& b) : x(static_cast<float>(a)),y(static_cast<float>(b)) {}

    Point (const IntType& a, const IntType& b) : x(static_cast<float>(a)),y(static_cast<float>(b)) {}

    ~Point() {}

    Point& multiply(float m)
    {
        x *= m;
        y *= m;
        return *this;
    }

    Point& multiply(const FloatType& ft)
    {
        return multiply(static_cast<float>(ft));
    }

    Point& multiply(const DoubleType& dt)
    {
        return multiply(static_cast<float>(dt));
    }

    Point& multiply(const IntType& it)
    {
        return multiply(static_cast<float>(it));
    }

    void toString()
    {
        std::cout << "Point { x: " << x << ", y: " << y << " }" << std::endl;
    }

private:
    float x{0}, y{0};
};

//=====================================

FloatType& FloatType::operator+= (float rhs)
{
    *value += rhs;

    return *this;
}

FloatType& FloatType::operator-= (float rhs)
{
    *value -= rhs;

    return *this;
}

FloatType& FloatType::operator*= (float rhs)
{
    *value *= rhs;

    return *this;
}

FloatType& FloatType::operator/= (float rhs)
{
    if (rhs == 0.0f)
    { 
        std::cout << "warning: floating point division by zero!" << std::endl; 
    }

    *value /= rhs;

    return *this;
}

FloatType& FloatType::pow( float ft )
{
    return powInternal( ft );
}

FloatType& FloatType::powInternal(float ft)
{
    *value = std::pow(*value, ft);
    return *this; 
}

FloatType& FloatType::pow( const FloatType& ft )
{
    return powInternal(static_cast<float>(ft));
}

FloatType& FloatType::pow( const DoubleType& dt )
{
    return powInternal(static_cast<float>(dt));
}

FloatType& FloatType::pow( const IntType& it )
{
    return powInternal(static_cast<float>(it));
}

FloatType& FloatType::apply(std::function<FloatType&(float&> func);
{
    return *this;
}

FloatType& FloatType::apply(void(*func)(float&));
{
    return *this;
}

//=====================================

DoubleType& DoubleType::operator+= (double rhs)
{
    *value += rhs;

    return *this;
}

DoubleType& DoubleType::operator-= (double rhs)
{
    *value -= rhs;

    return *this;
}

DoubleType& DoubleType::operator*= (double rhs)
{
    *value *= rhs;

    return *this;
}

DoubleType& DoubleType::operator/= (double rhs)
{
    if (rhs == 0.0)
    { 
        std::cout << "warning: floating point division by zero!" << std::endl; 
    }

    *value /= rhs;

    return *this;
}

DoubleType& DoubleType::powInternal (double dt)
{
    *value = std::pow(*value, dt);
    return *this;
}

DoubleType& DoubleType::pow( const double dt )
{
    return powInternal( dt );
}

DoubleType& DoubleType::pow( const FloatType& ft )
{
    return powInternal(static_cast<double>(ft));
}

DoubleType& DoubleType::pow( const DoubleType& dt )
{
    return powInternal(static_cast<double>(dt));
}

DoubleType& DoubleType::pow( const IntType& it )
{
    return powInternal(static_cast<double>(it));
}

DoubleType& DoubleType::apply(std::function<DoubleType&(double&> func);
{
    return *this;
}

DoubleType& DoubleType::apply(void(*func)(double&));
{
    return *this;
}

//=====================================

IntType& IntType::operator+= (int rhs)
{
    *value += rhs;

    return *this;
}

IntType& IntType::operator-= (int rhs)
{
    *value -= rhs;

    return *this;
}

IntType& IntType::operator*= (int rhs)
{
    *value *= rhs;

    return *this;
}

IntType& IntType::operator/= (int rhs)
{
    if (rhs == 0)
    { 
        std::cout << "error: integer division by zero is an error and will crash the program!" << std::endl; 
    }
    else
    {
        *value /= rhs;
    }

    return *this;
}

IntType& IntType::powInternal (const int it)
{
    *value = static_cast<int>(std::pow(*value, it));
    return *this;
}

IntType& IntType::pow( int it )
{
    return powInternal( it );
}

IntType& IntType::pow( const FloatType& ft )
{
    return powInternal(static_cast<int>(ft));
}

IntType& IntType::pow( const DoubleType& dt )
{
    return powInternal(static_cast<int>(dt));
}

IntType& IntType::pow( const IntType& it )
{
    return powInternal(static_cast<int>(it));
}

IntType& IntType::apply(std::function<IntType&(int&> func);
{
    return *this;
}

IntType& IntType::apply(void(*func)(int&));
{
    return *this;
}

//=====================================

void part3()
{
    FloatType ft( 5.5f );
    DoubleType dt( 11.1 );
    IntType it ( 34 );
    DoubleType pi( 3.14 );

    ft *= ft;
    ft *= ft;
    ft /= static_cast<float>(it);

    std::cout << "The result of FloatType^3 divided by IntType is: " << ft << std::endl;

    dt *= 3;
    dt += static_cast<double>(it);

    std::cout << "The result of DoubleType times 3 plus IntType is : " << dt << std::endl;

    it /= static_cast<int>(pi);
    it *= static_cast<int>(dt);
    it -= static_cast<int>(ft);

    std::cout << "The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: " << it << std::endl;

    it *= it;

    std::cout << "An operation followed by attempts to divide by 0, which are ignored and warns user: " << std::endl;
    
    it /= 0;
    it /= static_cast<int>(0.0f);
    it /= static_cast<int>(0.0);
    
    std::cout << it << std::endl;
    
    it *= static_cast<int>(ft);

    std::cout << "FloatType x IntType  =  " << it << std::endl;

    it += static_cast<int>(dt);
    it += static_cast<int>(ft);
    it *= 24;

    std::cout << "(IntType + DoubleType + FloatType) x 24 = " << it << std::endl;
}


void part4()
{
    // ------------------------------------------------------------
    //                          Power tests
    // ------------------------------------------------------------
    FloatType ft1(2);
    DoubleType dt1(2);
    IntType it1(2);    
    int floatExp = 2.0f;
    int doubleExp = 2.0;
    int intExp = 2;
    IntType itExp(2);
    FloatType ftExp(2.0f);
    DoubleType dtExp(2.0);
    
    // Power tests with FloatType
    std::cout << "Power tests with FloatType " << std::endl;
    std::cout << "pow(ft1, floatExp) = " << ft1 << "^" << floatExp << " = " << ft1.pow(floatExp)  << std::endl;
    std::cout << "pow(ft1, itExp) = " << ft1 << "^" << itExp << " = " << ft1.pow(itExp)  << std::endl;
    std::cout << "pow(ft1, ftExp) = " << ft1 << "^" << ftExp << " = " << ft1.pow(ftExp)  << std::endl;    
    std::cout << "pow(ft1, dtExp) = " << ft1 << "^" << dtExp << " = " << ft1.pow(dtExp)  << std::endl;    
    std::cout << "---------------------\n" << std::endl;  

    // Power tests with DoubleType
    std::cout << "Power tests with DoubleType " << std::endl;
    std::cout << "pow(dt1, doubleExp) = " << dt1 << "^" << doubleExp << " = " << dt1.pow(intExp)  << std::endl;
    std::cout << "pow(dt1, itExp) = " << dt1 << "^" << itExp << " = " << dt1.pow(itExp)  << std::endl;
    std::cout << "pow(dt1, ftExp) = " << dt1 << "^" << ftExp << " = " << dt1.pow(ftExp)  << std::endl;    
    std::cout << "pow(dt1, dtExp) = " << dt1 << "^" << dtExp << " = " << dt1.pow(dtExp)  << std::endl;    
    std::cout << "---------------------\n" << std::endl;    

    // Power tests with IntType
    std::cout << "Power tests with IntType " << std::endl;
    std::cout << "pow(it1, intExp) = " << it1 << "^" << intExp << " = " << it1.pow(intExp)  << std::endl;
    std::cout << "pow(it1, itExp) = " << it1 << "^" << itExp << " = " << it1.pow(itExp)  << std::endl;
    std::cout << "pow(it1, ftExp) = " << it1 << "^" << ftExp << " = " << it1.pow(ftExp)  << std::endl;    
    std::cout << "pow(it1, dtExp) = " << it1 << "^" << dtExp << " = " << it1.pow(dtExp)  << std::endl;    
    std::cout << "===============================\n" << std::endl; 

    // ------------------------------------------------------------
    //                          Point tests
    // ------------------------------------------------------------
    FloatType ft2(3.0f);
    DoubleType dt2(4.0);
    IntType it2(5);
    float floatMul = 6.0f;

    // Point tests with float
    std::cout << "Point tests with float argument:" << std::endl;
    Point p0(ft2, floatMul);
    p0.toString();   
    std::cout << "Multiplication factor: " << floatMul << std::endl;
    p0.multiply(floatMul); 
    p0.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with FloatType
    std::cout << "Point tests with FloatType argument:" << std::endl;
    Point p1(ft2, ft2);
    p1.toString();   
    std::cout << "Multiplication factor: " << ft2 << std::endl;
    p1.multiply(ft2); 
    p1.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with DoubleType
    std::cout << "Point tests with DoubleType argument:" << std::endl;
    Point p2(ft2, static_cast<float>(dt2));
    p2.toString();   
    std::cout << "Multiplication factor: " << dt2 << std::endl;
    p2.multiply(dt2); 
    p2.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with IntType
    std::cout << "Point tests with IntType argument:" << std::endl;
    Point p3(ft2, static_cast<float>(dt2));
    p3.toString();   
    std::cout << "Multiplication factor: " << it2 << std::endl;
    p3.multiply(it2); 
    p3.toString();   
    std::cout << "---------------------\n" << std::endl;
}


int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    ft += 2.0f;

    std::cout << "FloatType add result=" << ft << std::endl;

    ft -= 2.0f;

    std::cout << "FloatType subtract result=" << ft << std::endl;

    ft *= 2.0f;

    std::cout << "FloatType multiply result=" << ft << std::endl;

    ft /= 16.0f;

    std::cout << "FloatType divide result=" << ft << std::endl << std::endl;

    dt += 2.0;

    std::cout << "DoubleType add result=" << dt << std::endl;

    dt -= 2.0;

    std::cout << "DoubleType subtract result=" << dt << std::endl;

    dt *= 2.0;

    std::cout << "DoubleType multiply result=" << dt << std::endl;

    dt /= static_cast<double>(5.f);

    std::cout << "DoubleType divide result=" << dt << std::endl << std::endl;

    it += 2;

    std::cout << "IntType add result=" << it << std::endl;

    it -= 2;

    std::cout << "IntType subtract result=" << it << std::endl;

    it *= 2;

    std::cout << "IntType multiply result=" << it << std::endl;

    it /= 3;

    std::cout << "IntType divide result=" << it << std::endl << std::endl;

    it *= 1000;
    it /= 2;
    it -= 10;
    it += 100;

    std::cout << "Chain calculation = " << it << std::endl;

        // FloatType object instanciation and method tests
    // --------

    ft += 3.0f;
    ft *= 1.5f;
    ft /= 5.0f;

    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << ft << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << dt << std::endl;
    std::cout << "Initial value of it: " << it << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;

    dt *= static_cast<double>(it);
    dt /= static_cast<double>(5.0);
    dt += static_cast<double>(ft);

    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << dt << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;

    std::cout << "New value of it = it / 0 = "; 
    
    it /= 0;

    std::cout << it << std::endl;

    std::cout << "New value of ft = ft / 0 = ";
    
    ft /= 0;

    std::cout << ft << std::endl;

    std::cout << "New value of dt = dt / 0 = "; 
    
    dt /= 0;

    std::cout << dt << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    part3();

    part4();

    std::cout << "good to go!\n";

    return 0;
}



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */
 
/*
#include <iostream>

struct FloatType 
{
    float add( float lhs, float rhs);
    float subtract(float lhs, float rhs);
    float multiply(float lhs, float rhs);
    float divide(float lhs, float rhs);
};

float FloatType::add(float lhs, float rhs)
{
    return lhs + rhs;
}

float FloatType::subtract(float lhs, float rhs)
{
    return lhs - rhs;
}

float FloatType::multiply (float lhs, float rhs)
{
    return lhs * rhs;
}

float FloatType::divide (float lhs, float rhs)
{
    if (rhs == 0.0f)
    { 
        std::cout << std::endl << "warning, floating point division by zero returns 'inf' !" << std::endl; 
    }
    return lhs / rhs;
}

struct DoubleType 
{
    double add( double lhs, double rhs);
    double subtract(double lhs, double rhs);
    double multiply(double lhs, double rhs);
    double divide(double lhs, double rhs);
};

double DoubleType::add(double lhs, double rhs)
{
    return lhs + rhs;
}

double DoubleType::subtract(double lhs, double rhs)
{
    return lhs - rhs;
}

double DoubleType::multiply (double lhs, double rhs)
{
    return lhs * rhs;
}

double DoubleType::divide (double lhs, double rhs)
{
    if (rhs == 0.0)
    { 
        std::cout << std::endl << "warning, floating point division by zero returns 'inf' !" << std::endl; 
    } 
    return lhs / rhs;
}

struct IntType 
{
    int add( int lhs, int rhs);
    int subtract(int lhs, int rhs);
    int multiply(int lhs, int rhs);
    int divide(int lhs, int rhs);
};

int IntType::add(int lhs, int rhs)
{
    return lhs + rhs;
}

int IntType::subtract(int lhs, int rhs)
{
    return lhs - rhs;
}

int IntType::multiply (int lhs, int rhs)
{
    return lhs * rhs;
}

int IntType::divide (int lhs, int rhs)
{
    if (rhs == 0.0)
    { 
        std::cout << "error, integer division by zero will crash the program!" << std::endl;
        std::cout << "returning lhs" << std::endl;
        return lhs;
    } 
    return lhs / rhs;
}

int main() 

{
    FloatType ft;
    std::cout << "result of ft.add(): " << ft.add( 123.456f, 432.1f) << std::endl;
    std::cout << "result of ft.subtract(): " << ft.subtract( 123.456f, 432.1f) << std::endl;
    std::cout << "result of ft.multiply(): " << ft.multiply( 123.456f, 432.1f) << std::endl;
    std::cout << "result of ft.divide(): " << ft.divide( 123.456f, 432.1f) << std::endl;

    std::cout << "result of ft.add(): " << ft.add( 4444.56f, 0.0f)  << std::endl;
    std::cout << "result of ft.subtract(): " << ft.subtract( 4444.56f, 0.0f) << std::endl;
    std::cout << "result of ft.multiply(): " << ft.multiply( 4444.56f, 0.0f) << std::endl;
    std::cout << "result of ft.divide(): " << ft.divide( 4444.56f, 0.0f) << std::endl;

    DoubleType db;
    std::cout << "result of db.add(): " << db.add( 123.456, 432.1) << std::endl;
    std::cout << "result of db.subtract(): " << db.subtract( 123.456, 432.1) << std::endl;
    std::cout << "result of db.multiply(): " << db.multiply( 123.456, 432.1) << std::endl;
    std::cout << "result of db.divide(): " << db.divide( 123.456, 432.1) << std::endl;

    std::cout << "result of db.add(): " << db.add( 123.456, 0.0) << std::endl;
    std::cout << "result of db.subtract(): " << db.subtract( 123.456, 0.0) << std::endl;
    std::cout << "result of db.multiply(): " << db.multiply( 123.456, 0.0) << std::endl;
    std::cout << "result of db.divide(): " << db.divide( 123.456, 0.0) << std::endl;

    IntType i;
    std::cout << "result of i.add(): " << i.add( 10, 20) << std::endl;
    std::cout << "result of i.subtract(): " << i.subtract( 10, 20) << std::endl;
    std::cout << "result of i.multiply(): " << i.multiply( 10, 20) << std::endl;
    std::cout << "result of i.divide(): " << i.divide( 10, 20) << std::endl;

    std::cout << "result of i.add(): " << i.add( 10, 0) << std::endl;
    std::cout << "result of i.subtract(): " << i.subtract( 10, 0) << std::endl;
    std::cout << "result of i.multiply(): " << i.multiply( 10, 0) << std::endl;
    std::cout << "result of i.divide(): " << i.divide( 10, 0) << std::endl;

    std::cout << "good to go!" << std::endl;
}

*/
