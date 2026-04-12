#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n,k;
    string s;
    cin >> n >> s >> k;
    char key=s[k-1];
    for(int i=0;i<n;i++)
    {
        if(s[i]!=key) s[i]='*';
    }
    cout << s;
    return 0;
}
