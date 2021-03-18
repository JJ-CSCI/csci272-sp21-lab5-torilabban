//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write the assignment code here
class Real{
  protected:
  double a;

  public:
  Real(double c){a=c;} 
  Real(){}
  double GetReal(){
    return a;} 
  double operator+(double num){
    return a+num;
  }
};

class Complex:protected Real{
  protected:
  double a1;
  //double b2;
  
  public:
  Complex(){}
  Complex(double c2,double d3) {
  Real()=c2; //b2=c2;
  a1=d3;} 

  double GetImaginary() const {
  return a1;
  //return b2;
  }

 double operator+ (double num2){
   return a1+num2;
   //return b2+num2;
 }
};

class Surreal: protected Complex{
  protected:
  double a3,b3,c3;

  public:
  
  Surreal(double d3,double e3,double f3){
    a1=d3;
    a1=e3;
    c3=f3;
  }
  double GetSurreal(){
    return c3;}
  double operator+ (double num3){
    return GetReal() + num3;
    return GetImaginary() + num3;
    return c3 + num3;
  }

};


//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
        REQUIRE( r.GetImaginary() == 22.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
        REQUIRE( r.GetImaginary() == 22.0 );
        REQUIRE( r.GetSurreal() == 32.0 );
    }
}
//------------------------------
