#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(),a.end());
    deque<ll> d,e;
    int ix=1,iy=n-1;
    d.push_front(0);
    if(n%2){
        for(int i=0; i<n/2; i++){
            if(i%2==0){
                d.push_front(iy);
                iy--;
                d.push_back(iy);
                iy--;
            }else{
                d.push_front(ix);
                ix++;
                d.push_back(ix);
                ix++;
            }
        }
    }else{
        for(int i=1; i<n/2; i++){
            if(i%2){
                d.push_front(iy);
                iy--;
                d.push_back(iy);
                iy--;
            }else{
                d.push_front(ix);
                ix++;
                d.push_back(ix);
                ix++;
            }
        }
        d.push_front(n/2);
    }
    ix=0,iy=n-2;
    e.push_front(n-1);
    if(n%2){
        for(int i=0; i<n/2; i++){
            if(i%2){
                e.push_front(iy);
                iy--;
                e.push_back(iy);
                iy--;
            }else{
                e.push_front(ix);
                ix++;
                e.push_back(ix);
                ix++;
            }
        }
    }else{
        for(int i=1; i<n/2; i++){
            if(i%2==0){
                e.push_front(iy);
                iy--;
                e.push_back(iy);
                iy--;
            }else{
                e.push_front(ix);
                ix++;
                e.push_back(ix);
                ix++;
            }
        }
        e.push_front(n/2);
    }
    vector<ll> b(n),c(n);
    for(int i=0; i<n; i++){
        b[i]=a[d.front()];
        d.pop_front();
        c[i]=a[e.front()];
        e.pop_front();
    }
    //cout<<endl;
    ll ans=0,ans2=0;
    for(int i=0; i<n-1; i++){
        ans+=abs(b[i]-b[i+1]);
        ans2+=abs(c[i]-c[i+1]);
    }
    cout<<max(ans,ans2)<<endl;
}