#include<iostream>
//#include<CastingInterop.h>
#include<string>
using namespace std;

int main()
{
    char arr[3];
    int arr1[3];
    string y;
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }
    string s[1000];
    for (int i = 0; i < 3; i++)
    {
        s[i] = arr[i];
        
    }
    string w;

    for (int i = 0; i < 3; i++)
    {
        w += s[i]; 
    }

    //cout << s[0];
    //cout << w;
    int num = stoi(w);
    //cout << num<<endl ; 
    if (num % 4 == 0)
        cout << "YES";
    else
        cout << "NO";
}