#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(){
        string s;
        cin>>s;
        ll flag=0;
        ll l=s.size();

        for(ll i=0;i<l;++i){
            if(s[i]=='A'){
                flag++;
                break;
            }
        }
        for(ll i=0;i<l;++i){
            if(s[i]=='B'){
                flag++;
                break;
            }
        }
        if(flag==2){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
}