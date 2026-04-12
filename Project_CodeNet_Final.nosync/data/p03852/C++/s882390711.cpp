#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    char c;
    cin >> c;

    if(c=='a' or c=='i' or c=='u' or c=='e' or c=='o')
        cout << "vowel" << endl;
    else
        cout << "consonant" << endl;
}