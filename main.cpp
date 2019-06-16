#include <iostream>
#include <algorithm>
#include <vector> 
#include <cmath>
#include <set> 

//TColon 
//PowerMod Calcualtor and Perfect Square Finder  
#define MOD 1238513
using namespace std;

 int modulo(int a,long long int b,int n){
    long long x=1,y=a; 
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%n;
        }
        y = (y*y)%n; // squaring the base
        b /= 2;
    }
    return x%n;
}

long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}

long long int gcd (long long int n1, long long int n2) {
    long long int tmp;
    while (n2 != 0) {
        tmp = n1;
        n1 = n2;
        n2 = tmp % n2;
    }
    return n1;
}

int power(int base, unsigned int exp){

    if (exp == 0)
        return 1;
    int temp = power(base, exp/2);
    if (exp%2 == 0)
        return temp*temp;
    else
        return base*temp*temp;

}

bool isPerfectSquare(long double x)
{  
  // Find floating point value of 
  // square root of x.
  long double sr = sqrt(x);
 
  // If square root is an integer
  return ((sr - floor(sr)) == 0);
}

long long int factorial(long long int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main (){
	
	 int N = 0; //modulus

   int a = 2; // co-prime value

   

   cout << "Enter your N value: ";

   cin >> N;

   

   //First: find a such that a and N are relatively prime:

   while (__gcd(a,N) != 1){

     a++;

   }

  

  //Evaluate 2^k! mod N for k = 2, 3, 4, and find GCD of 2^k-1 mod N:

  int tempExponent = 0;

  int tempIterationValue = 0;

  cout << "Evaluating 2^k! mod " << N << " and finding GCD of 2^k! -1 mod N: " << endl;

  cout << "k = \t2^k! mod N\t2^l!-1 =\tGCD of 2^k! -1 mod N" << endl;

  

  for (int i = 2; i < 35; i++){

   

    tempExponent = factorial(i);

    tempIterationValue = modulo(2,tempExponent,N);

    cout << i << "\t" << tempIterationValue << "\t\t" << tempIterationValue-1 << "\t\t" << __gcd((tempIterationValue-1), N) << endl;

    

  }

 

  return 0;
  }
