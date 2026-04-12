#include <bits/stdc++.h> 
#define ll long long 
#define ld long double
#define ull unsigned long long
#define yes cout<<"Yes"<<"\n"
#define no cout<<"No"<<"\n"
using namespace std;
const double pi=3.14159265358979323846;
const int MAX_CHARS = 256; 
  
// This function receives text and shift and 
// returns the encrypted text 
string encrypt(string text, int s) 
{ 
    string result = ""; 
  
    // traverse text 
    for (int i=0;i<text.length();i++) 
    { 
        // apply transformation to each character 
        // Encrypt Uppercase letters 
        if (isupper(text[i])) 
            result += char(int(text[i]+s-65)%26 +65); 
  
    // Encrypt Lowercase letters 
    else
        result += char(int(text[i]+s-97)%26 +97); 
    } 
  
    // Return the resulting string 
    return result; 
} 
  
// Driver program to test the above function 
int main() 
{ 
    int n;
    cin>>n;
    if(n>=30)
    yes;
    else 
    no;
} 