#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int cnta=0,cntb=0;
    for (int i=0;i<n;i++){
        if(s[i]=='A')
            cnta++;
        if(s[i]=='B')
            cntb++;
    }
    if (cnta >=2 && cntb>0)
        cout<<"Yes";
    else if (cntb>=2 && cnta>0)
        cout<<"Yes";
    else
        cout<<"No";



    return 0;
}
