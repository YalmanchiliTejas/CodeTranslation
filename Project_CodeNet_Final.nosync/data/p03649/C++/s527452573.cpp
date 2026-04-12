#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

int main(){
    int N;
    cin >> N;
    vector<ll> A(N,0);
    ll sum_=0;
    for(auto &a: A){
        cin >> a;
        sum_+=a;
    }

    ll dif=max(0LL,sum_-N*(N-1));
    ll cnt=0;
    priority_queue<ll, vector<ll>, less<ll> > que;
    for(int i=0; i<N; i++){
        cnt+=(A[i]+dif)/(N+1);
        A[i]=(A[i]+dif)%(N+1);
        if(cnt>dif){
            A[i]+=(cnt-dif)*(N+1);
            cnt=dif;
        }
        que.push(A[i]);
    }

    //cout_vec(A);

    ll tmp=0;
    while(que.top()+tmp>=N){
        ll top=que.top()+tmp;
        //cout << que.top() << ' '  << tmp << endl;
        que.pop();
        ll k=top/N;
        tmp+=k;
        que.push(top%N-tmp);
    }
    cout << dif+tmp << endl;
}