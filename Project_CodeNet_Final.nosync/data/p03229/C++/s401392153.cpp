#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N),B(N);
    for(ll i=0; i<N; i++){
        cin >> A[i];
        B[i] = A[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    reverse(B.begin(),B.end());
    
    list<ll> lst1;
    bool flag1=true; ll a1=1,b1=0;
    for(ll i=0; i<N;){
        if(i==0){
            lst1.push_back(A[0]);
            i++;
        }
        else {
            if(flag1){
                lst1.push_front(B[b1++]);
                lst1.push_back(B[b1++]);
                i+=2;
                flag1=false;
            }
            else {
                lst1.push_front(A[a1++]);
                lst1.push_back(A[a1++]);
                i+=2;
                flag1=true;
            }
        }
    }
    ll ans1=0, x,y; ll cnt1=0;
    for(auto itr=lst1.begin(); itr!=lst1.end(); itr++,cnt1++){
        if(cnt1==N-1) break;
        x = *itr; y = *std::next(itr,1);
        ans1 += abs(x-y);
    }
    
    list<ll> lst2;
    bool flag2=true; ll a2=0,b2=1;
    for(ll i=0; i<N;){
        if(i==0){
            lst2.push_back(B[0]);
            i++;
        }
        else {
            if(!flag2){
                lst2.push_front(B[b2++]);
                lst2.push_back(B[b2++]);
                i+=2;
                flag2=true;
            }
            else {
                lst2.push_front(A[a2++]);
                lst2.push_back(A[a2++]);
                i+=2;
                flag2=false;
            }
        }
    }
    ll ans2=0; ll cnt2=0;
    for(auto itr=lst2.begin(); itr!=lst2.end(); itr++,cnt2++){
        if(cnt2==N-1) break;
        x = *itr; y = *std::next(itr,1);
        ans2 += abs(x-y);
    }
    
    cout << max(ans1,ans2) << endl;
}
