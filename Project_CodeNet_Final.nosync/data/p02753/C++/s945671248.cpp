#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
int main ()
{  string s;
	cin>>s;
	ll c1=0 , c2=0 ;
	for(int i=0 ; i<3;i++)
    {
        if(s[i]=='A') c1++ ;
        if(s[i]=='B') c2++ ;
    }
    if(c1==0|| c2==0){cout<<"No"<<endl;}
    else {cout<<"Yes" << endl ;}
    return 0 ;
}

