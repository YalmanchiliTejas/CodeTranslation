//BISMILLAHHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
using namespace std;
typedef long long int            ll;
typedef unsigned long long int   ull;
#define min3(a,b,c)              min(a,min(b,c))
#define F                        first
#define S                        second
#define PB                       push_back
#define MP                       make_pair
#define PI                       2*acos(0.0)
#define REP(i,a,b)               for(int i = a; i<=b; i++)
int main()
{
    string s;
    int a=0,b=0;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='A')a++;
        else b++;
    }
    if(a==0 || b==0){
        cout<<"No"<<endl;
    }
    else cout<<"Yes"<<endl;
    return 0;

}
