#include <iostream> pre processor directive
#include <string>
#include <iomanip>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    char c;
    cin>>c;
    if(c=='a' || c=='e' || c=='i' || c=='u' || c=='o'){cout<<"vowel"<<endl;}
    else{cout<<"consonant"<<endl;}
}
