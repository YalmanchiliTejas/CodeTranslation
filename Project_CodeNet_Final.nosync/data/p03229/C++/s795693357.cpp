#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;

int N;
int A[100000];
deque<int> deq;

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    sort(A,A+N);

    ll ans=0;

    int l=1, r=N-1;
    bool right=true;
    int cnt=0;
    deq.push_back(A[0]);
    repn(i,N-1){
        if(right){
            if(cnt==0){
                deq.push_front(A[r]);
                r--;
                cnt++;
            }else if(cnt==1){
                deq.push_back(A[r]);
                r--;
                cnt=0;
                right=false;
            }
        }else{
            if(cnt==0){
                deq.push_front(A[l]);
                l++;
                cnt++;
            }else if(cnt==1){
                deq.push_back(A[l]);
                l++;
                cnt=0;
                right=true;
            }
        }
    }
    ll res=0;
    int a1,a2=deq.front();
    deq.pop_front();
    rep(i,N-1){
        a1=a2;
        a2=deq.front();
        deq.pop_front();
        res+=abs(a1-a2);
    }
    ans=max(ans,res);



    l=0, r=N-2;
    right=false;
    cnt=0;
    deq.clear();
    deq.push_back(A[N-1]);
    repn(i,N-1){
        if(right){
            if(cnt==0){
                deq.push_front(A[r]);
                r--;
                cnt++;
            }else if(cnt==1){
                deq.push_back(A[r]);
                r--;
                cnt=0;
                right=false;
            }
        }else{
            if(cnt==0){
                deq.push_front(A[l]);
                l++;
                cnt++;
            }else if(cnt==1){
                deq.push_back(A[l]);
                l++;
                cnt=0;
                right=true;
            }
        }
    }
    res=0;
    a1=0,a2=deq.front();
    deq.pop_front();
    rep(i,N-1){
        a1=a2;
        a2=deq.front();
        deq.pop_front();
        res+=abs(a1-a2);
    }
    ans=max(ans,res);

    cout<<ans<<endl;
}