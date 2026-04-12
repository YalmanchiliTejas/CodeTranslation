#include<iostream>
//#include<CastingInterop.h>
#include<string>
#include <sstream>
using namespace std;

int main()
{
    char arr[3];
    string s=""; 
   
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
        s += arr[i]; 
    }
   
    stringstream str(s); 
    int num; 
    str >> num; 
    if (num % 4 == 0)
        cout << "YES";
    else
        cout << "NO";
    return 0; 
}