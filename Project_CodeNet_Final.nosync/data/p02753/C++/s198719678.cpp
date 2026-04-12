                   /**Bismillahir Rahmanir Rahim.**/
/*
         Md.Fagun Molla
         18ICTCSE006
         BSMRSTU(SHIICT)
*/
#include <bits/stdc++.h>
using namespace std;


#define  gcd(a,b)         __gcd(a,b)
#define  lcm(a,b)         (a*b)/gcd(a,b)
#define  ll               long long
#define  vi               std::vector<int>
#define  pb               push_back
#define  MAX              100007
#define  End              return 0;
#define                   pi acos(-1)


int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

    int T=1;// cin>>T;
    while(T--){
        string s;
        cin>>s;
        bool f=true;
        for(int i=0; i<s.size()-1; i++){
            if(s[i]!=s[i+1]){
                f=false;
                break;
            }

        }
        if(f)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    End;
}
/* pray for me
Do before die
*/



