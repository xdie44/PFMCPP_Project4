/*
 Project 4 - Part 3 / 9
 Video: Chapter 4 Part 3 
 Casting

 Create a branch named Part3
 
 do not remove anything from main().  you'll be revising your main() to work with these new code changes.
 
    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.

 1) remove your functions that accepted a User-Defined Type
 
 2) remove any getValue() functions if you added them
 
 3) move all of your add/subtract/multiply/divide implementations out of the class.
  
 4) add user-defined conversion functions that convert to the numeric type your object holds.
        i.e. if your type holds an int, you'll need an operator int() function.
 
 5) make your member variable private.
         this conversion function should be the ONLY WAY to access the held value.
         use the proper casting technique to invoke this conversion function
 
 6) clean up any forward declaration that you might have.
 
 7) make sure it compiles & runs without errors.
 
 8) use your knowledge of casting to remove any conversion warnings. 

 9) insert 'part3();' before the 'good to go' at the end of your main(); 
        move this part3 function to before main()

 10) click the [run] button.  Clear up any errors or warnings as best you can.

 */

void part3()
{
    FloatType ft( 5.5f );
    DoubleType dt( 11.1 );
    IntType it ( 34 );
    DoubleType pi( 3.14 );

    std::cout << "The result of FloatType^3 divided by IntType is: " << ft.multiply( ft ).multiply( ft ).divide( it ) << std::endl;
    std::cout << "The result of DoubleType times 3 plus IntType is : " << dt.multiply( 3 ).add( it ) << std::endl;
    std::cout << "The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: " << it.divide( pi ).multiply( dt ).subtract( ft ) << std::endl;
    std::cout << "An operation followed by attempts to divide by 0, which are ignored and warns user: " << std::endl;
    std::cout << it.multiply(it).divide(0).divide(0.0f).divide(0.0) << std::endl;
    
    std::cout << "FloatType x IntType  =  " << it.multiply( ft ) << std::endl;
    std::cout << "(IntType + DoubleType + FloatType) x 24 = " << it.add( dt ).add( ft ).multiply( 24 ) << std::endl;
}

/*
your program should generate the following output EXACTLY.
This includes the warnings.
The output should have zero warnings.
Use a service like https://www.diffchecker.com/diff to compare your output. 

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
good to go!




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

struct DoubleType;
struct IntType;

struct FloatType
{
    FloatType (float val) : value (new float(val)) 
    {

    }
    ~FloatType ()
    {
        delete value;
        value = nullptr;
    }

    float* value = nullptr;

    FloatType& add(float rhs);
    FloatType& subtract(float rhs);
    FloatType& multiply(float rhs);
    FloatType& divide(float rhs);

    FloatType& add(FloatType& ft);
    FloatType& subtract(FloatType& ft);
    FloatType& multiply(FloatType& ft);
    FloatType& divide(FloatType& ft);

    FloatType& add(DoubleType& dt);
    FloatType& subtract(DoubleType& dt);
    FloatType& multiply(DoubleType& dt);
    FloatType& divide(DoubleType& dt);

    FloatType& add(IntType& it);
    FloatType& subtract(IntType& it);
    FloatType& multiply(IntType& it);
    FloatType& divide(IntType& it);
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

    double* value = nullptr;

    DoubleType& add(double rhs);
    DoubleType& subtract(double rhs);
    DoubleType& multiply(double rhs);
    DoubleType& divide(double rhs);

    DoubleType& add(FloatType& ft);
    DoubleType& subtract(FloatType& ft);
    DoubleType& multiply(FloatType& ft);
    DoubleType& divide(FloatType& ft);

    DoubleType& add(DoubleType& dt);
    DoubleType& subtract(DoubleType& dt);
    DoubleType& multiply(DoubleType& dt);
    DoubleType& divide(DoubleType& dt);

    DoubleType& add(IntType& it);
    DoubleType& subtract(IntType& it);
    DoubleType& multiply(IntType& it);
    DoubleType& divide(IntType& it);
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

    int* value = nullptr;

    IntType& add(int rhs);
    IntType& subtract(int rhs);
    IntType& multiply(int rhs);
    IntType& divide(int rhs);

    IntType& add(FloatType& ft);
    IntType& subtract(FloatType& ft);
    IntType& multiply(FloatType& ft);
    IntType& divide(FloatType& ft);

    IntType& add(DoubleType& dt);
    IntType& subtract(DoubleType& dt);
    IntType& multiply(DoubleType& dt);
    IntType& divide(DoubleType& dt);

    IntType& add(IntType& it);
    IntType& subtract(IntType& it);
    IntType& multiply(IntType& it);
    IntType& divide(IntType& it);
};



FloatType& FloatType::add (float rhs)
{
    *value += rhs;

    return *this;
}

FloatType& FloatType::subtract (float rhs)
{
    *value -= rhs;

    return *this;
}

FloatType& FloatType::multiply (float rhs)
{
    *value *= rhs;

    return *this;
}

FloatType& FloatType::divide (float rhs)
{
    if (rhs == 0.0f)
    { 
        std::cout << "warning: floating point division by zero!" << std::endl; 
    }

    *value /= rhs;

    return *this;
}

FloatType& FloatType::add(FloatType& ft)
{
    return add(*ft.value);
}

FloatType& FloatType::subtract (FloatType& ft)
{
    return subtract(*ft.value);
}

FloatType& FloatType::multiply (FloatType& ft)
{
    return multiply(*ft.value);
}

FloatType& FloatType::divide (FloatType& ft)
{
    return divide(*ft.value);
}

FloatType& FloatType::add (DoubleType& dt)
{
    return add(*dt.value);
}

FloatType& FloatType::subtract (DoubleType& dt)
{
    return subtract(*dt.value);
}

FloatType& FloatType::multiply (DoubleType& dt)
{
    return multiply(*dt.value);
}

FloatType& FloatType::divide (DoubleType& dt)
{
    return divide(*dt.value);
}

FloatType& FloatType::add (IntType& it)
{
    return add(*it.value);
}

FloatType& FloatType::subtract (IntType& it)
{
    return subtract(*it.value);
}

FloatType& FloatType::multiply (IntType& it)
{
    return multiply(*it.value);
}

FloatType& FloatType::divide (IntType& it)
{
    return divide(*it.value);
}


DoubleType& DoubleType::add (double rhs)
{
    *value += rhs;

    return *this;
}

DoubleType& DoubleType::subtract (double rhs)
{
    *value -= rhs;

    return *this;
}

DoubleType& DoubleType::multiply (double rhs)
{
    *value *= rhs;

    return *this;
}

DoubleType& DoubleType::divide (double rhs)
{
    if (rhs == 0.0)
    { 
        std::cout << "warning: floating point division by zero!" << std::endl; 
    }

    *value /= rhs;

    return *this;
}

DoubleType& DoubleType::add(FloatType& ft)
{
    return add(*ft.value);
}

DoubleType& DoubleType::subtract (FloatType& ft)
{
    return subtract(*ft.value);
}

DoubleType& DoubleType::multiply (FloatType& ft)
{
    return multiply(*ft.value);
}

DoubleType& DoubleType::divide (FloatType& ft)
{
    return divide(*ft.value);
}

DoubleType& DoubleType::add (DoubleType& dt)
{
    return add(*dt.value);
}

DoubleType& DoubleType::subtract (DoubleType& dt)
{
    return subtract(*dt.value);
}

DoubleType& DoubleType::multiply (DoubleType& dt)
{
    return multiply(*dt.value);
}

DoubleType& DoubleType::divide (DoubleType& dt)
{
    return divide(*dt.value);
}

DoubleType& DoubleType::add (IntType& it)
{
    return add(*it.value);
}

DoubleType& DoubleType::subtract (IntType& it)
{
    return subtract(*it.value);
}

DoubleType& DoubleType::multiply (IntType& it)
{
    return multiply(*it.value);
}

DoubleType& DoubleType::divide (IntType& it)
{
    return divide(*it.value);
}


IntType& IntType::add (int rhs)
{
    *value += rhs;

    return *this;
}

IntType& IntType::subtract (int rhs)
{
    *value -= rhs;

    return *this;
}

IntType& IntType::multiply (int rhs)
{
    *value *= rhs;

    return *this;
}

IntType& IntType::divide (int rhs)
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

IntType& IntType::add(FloatType& ft)
{
    return add(*ft.value);
}

IntType& IntType::subtract (FloatType& ft)
{
    return subtract(*ft.value);
}

IntType& IntType::multiply (FloatType& ft)
{
    return multiply(*ft.value);
}

IntType& IntType::divide (FloatType& ft)
{
    return divide(*ft.value);
}

IntType& IntType::add (DoubleType& dt)
{
    return add(*dt.value);
}

IntType& IntType::subtract (DoubleType& dt)
{
    return subtract(*dt.value);
}

IntType& IntType::multiply (DoubleType& dt)
{
    return multiply(*dt.value);
}

IntType& IntType::divide (DoubleType& dt)
{
    return divide(*dt.value);
}

IntType& IntType::add (IntType& it)
{
    return add(*it.value);
}

IntType& IntType::subtract (IntType& it)
{
    return subtract(*it.value);
}

IntType& IntType::multiply (IntType& it)
{
    return multiply(*it.value);
}

IntType& IntType::divide (IntType& it)
{
    return divide(*it.value);
}

int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << *ft.add( 2.0f ).value << std::endl;
    std::cout << "FloatType subtract result=" << *ft.subtract( 2.0f ).value << std::endl;
    std::cout << "FloatType multiply result=" << *ft.multiply( 2.0f ).value << std::endl;
    std::cout << "FloatType divide result=" << *ft.divide( 16.0f).value << std::endl << std::endl;

    std::cout << "DoubleType add result=" << *dt.add(2.0).value << std::endl;
    std::cout << "DoubleType subtract result=" << *dt.subtract(2.0).value << std::endl;
    std::cout << "DoubleType multiply result=" << *dt.multiply(2.0).value << std::endl;
    std::cout << "DoubleType divide result=" << *dt.divide(5.f).value << std::endl << std::endl;

    std::cout << "IntType add result=" << *it.add(2).value << std::endl;
    std::cout << "IntType subtract result=" << *it.subtract(2).value << std::endl;
    std::cout << "IntType multiply result=" << *it.multiply(2).value << std::endl;
    std::cout << "IntType divide result=" << *it.divide(3).value << std::endl << std::endl;
    std::cout << "Chain calculation = " << *(it.multiply(1000).divide(2).subtract(10).add(100)).value << std::endl;

        // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << *ft.add( 3.0f ).multiply(1.5f).divide(5.0f).value << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << *dt.value << std::endl;
    std::cout << "Initial value of it: " << *it.value << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << *(dt.multiply(it).divide(5.0f).add(ft).value) << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << *it.divide(0).value << std::endl;
    std::cout << "New value of ft = ft / 0 = " << *ft.divide(0).value << std::endl;
    std::cout << "New value of dt = dt / 0 = " << *dt.divide(0).value << std::endl;

    std::cout << "---------------------\n" << std::endl; 

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
