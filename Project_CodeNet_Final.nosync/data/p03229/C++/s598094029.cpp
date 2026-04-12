#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <functional> // std::function<void(int)>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int Dy[8] = {-1,-1,0,1,1,1,0,-1};
int Dx[8] = {0,1,1,1,0,-1,-1,-1};
const int mod = 1000000007;
const int inf = mod*mod;
const int d5 = 100100;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(All(a));
    deque<int> Q,P,R,O;
    for(auto i:a)Q.push_back(i);
    O=Q;
    int i=Q.front();Q.pop_front();
    P.push_back(i);
    int turn=0;
    while(true){
        if(turn==0){
            if(!Q.empty()){
                i=Q.back();
                Q.pop_back();
                P.push_back(i);
            }
            else break;
            if(!Q.empty()){
                i=Q.back();
                Q.pop_back();
                P.push_front(i);
            }
            else break;
            turn=1;
        }
        else{
            if(!Q.empty()){
                i=Q.front();
                Q.pop_front();
                P.push_back(i);
            }
            else break;
            if(!Q.empty()){
                i=Q.front();
                Q.pop_front();
                P.push_front(i);
            }
            else break;
            turn=0;
        }
    }
    i=O.back();O.pop_back();
    R.push_back(i);
    turn=1;
    while(true){
        if(turn==0){
            if(!O.empty()){
                i=O.back();
                O.pop_back();
                R.push_back(i);
            }
            else break;
            if(!O.empty()){
                i=O.back();
                O.pop_back();
                R.push_front(i);
            }
            else break;
            turn=1;
        }
        else{
            if(!O.empty()){
                i=O.front();
                O.pop_front();
                R.push_back(i);
            }
            else break;
            if(!O.empty()){
                i=O.front();
                O.pop_front();
                R.push_front(i);
            }
            else break;
            turn=0;
        }
    }
    int res1=0,res2=0;
    for(int i=0;i<n-1;i++){
        res1+=abs(P[i]-P[i+1]);
    }
    for(int i=0;i<n-1;i++){
        res2+=abs(R[i]-R[i+1]);
    }
    cout<<max(res1,res2)<<endl;
}