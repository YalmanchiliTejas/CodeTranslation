#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
int main()
{
    string s;
    cin>>s;
    if(s.find("AB")!=string::npos||s.find("BA")!=string::npos)
        cout<<"Yes";
    else
        cout<<"No";
    cout<<endl;
    return 0;
}
