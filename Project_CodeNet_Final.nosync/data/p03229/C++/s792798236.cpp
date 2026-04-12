#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N),B;
    rep(i,N){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    deque<ll> que,rue;
    rep(i,N){
        que.push_back(A[i]);
    }
    rue.push_back(que.front());
    que.pop_front();
    bool flag = true;
    while(!que.empty()){
        if(flag){
            rue.push_front(que.back());
            que.pop_back();
            if(que.empty())break;
            rue.push_back(que.back());
            que.pop_back();
            flag = !flag;
        }else{
            rue.push_front(que.front());
            que.pop_front();
            if(que.empty())break;
            rue.push_back(que.front());
            que.pop_front();
            flag = !flag;
        }

    }
    ll sum1 = 0;
    rep(i,N-1){
        sum1 += abs(rue[i+1]-rue[i]);
    }
    que = deque<ll>();
    rue = deque<ll>();
    
    rep(i,N){
        que.push_back(A[i]);
    }
    rue.push_back(que.back());
    que.pop_back();
    flag = false;
    while(!que.empty()){
        if(flag){
            rue.push_front(que.back());
            que.pop_back();
            if(que.empty())break;
            rue.push_back(que.back());
            que.pop_back();
            flag = !flag;
        }else{
            rue.push_front(que.front());
            que.pop_front();
            if(que.empty())break;
            rue.push_back(que.front());
            que.pop_front();
            flag = !flag;
        }

    }
    ll sum2 = 0;
    rep(i,N-1){
        sum2 += abs(rue[i+1]-rue[i]);
    }
    cout << max(sum1, sum2) << endl;
    /*
    B = vector<ll>();

    rep(i,N){
        que.push_back(A[i]);
    }
    rep(i,N){
        if(i%2 == 1){
            B.push_back(que.front());
            que.pop_front();
        }else{
            B.push_back(que.back());
            que.pop_back();
        }
    }
    ll sum2 = 0;
    rep(i,N-1){
        sum2 += abs(B[i+1]-B[i]);
    }
    cout << max(sum1, sum2) << endl;*/
}
