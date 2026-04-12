#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    string s,s2;
    cin >> s;
    ll l=s.size(),l2;
    ll ans=0;
    int k;
    cin >> k;
    l2=l;
    ll l3;
    int kk=0;
    vector <ll> v;
    rep(i,l){
        s2=s[i];
        if(atoi(s2.c_str())!=0){
            v.push_back(i);
        }
    }
    int vl=v.size();

    if(k==1 and l>=1){
        rep(i,10){
            if(i!=0){
                s2=s[0];
                if(i<=atoi(s2.c_str())){
                    ans+=l;
                }
                else{
                    ans+=(l-1);
                }
            }
        }
        cout << ans << endl;
    }
    else if(k==2 and l>=2){
        rep(i,10){
            l=l2;
            if(i!=0){
            s2=s[0];
            if(i<atoi(s2.c_str())){
                ans+=9*l*(l-1)/2;
            }
            else if(i==atoi(s2.c_str())){
                ans+=9*(l-1)*(l-2)/2;
                l=l2;
                if(vl==1){
                    continue;
                }
                else{
                l-=v[1]-1;
                    
                rep(j,10){
                    
                    kk=0;
                    if(j!=0){
                    s2=s[v[1]];
                    if(j<=atoi(s2.c_str())){
                        ans+=l-1;
                    }
                    else{
                        ans+=l-2;
                    }
                    }
                }
                }
            }
            else{
                ans+=9*(l-1)*(l-2)/2;
            }
            }
            }
            cout << ans << endl;
        }
        else if(k==3 and l>=3){
            rep(i,10){
                l=l2;
                if(i!=0){
                s2=s[0];
                if(i<atoi(s2.c_str())){
                    ans+=81*l*(l-1)*(l-2)/6;
                }
            else if(i==atoi(s2.c_str())){
                ans+=81*(l-3)*(l-1)*(l-2)/6;
                if(vl==1){
                    continue;
                }
                else{
                    l-=v[1]-1;
                    l3=l;
                rep(j,10){
                    l=l3;
                    if(j!=0){
                    s2=s[1];
                    if(j<atoi(s2.c_str())){
                        ans+=9*(l-1)*(l-2)/2;
                    }
                    else if(j==atoi(s2.c_str())){
                        ans+=9*(l-2)*(l-3)/2;
                        if(vl<=2){
                            continue;
                        }
                        else{
                            l-=v[2]-v[1]-1;
                        rep(ii,10){
                            if(ii!=0){
                                s2=s[2];
                                if(ii<=atoi(s2.c_str())){
                                    ans+=l-2;
                                }
                                else{
                                    ans+=l-3;
                                }
                            }
                        }
                        }
                    }
                    else{
                        ans+=9*(l-2)*(l-3)/2;
                    }
                    }
                }
                }
            }
            else{
                ans+=81*(l-3)*(l-1)*(l-2)/6;
            }
            }
            }
            cout << ans << endl;








        }
        else{
            cout << 0 << endl;
        }
    
    

    return 0;
}