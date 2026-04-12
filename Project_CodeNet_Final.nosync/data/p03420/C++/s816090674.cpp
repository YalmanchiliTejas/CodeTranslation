#include<bits/stdc++.h>
using namespace std;

//typedef
typedef long long LL;
typedef unsigned int UINT;
typedef unsigned long long ULL;
typedef set<int, greater<int> > setdownINT;
typedef set<long long, greater<long long> > setdownLL;
typedef priority_queue<int, vector<int>, greater<int> > priqueupINT;
typedef priority_queue<long long, vector<long long>, greater<long long> > priqueupLL;
//container utill
#define ALL(v) (v).begin(),(v).end()
#define sortdown(v) sort((v).begin(),(v).end()), reverse((v).begin(),(v).end())
#define PB(a) push_back(a)
#define MP make_pair
#define MT make_tuple
//constant
#define PI 3.141592653589793

int main(){
    //input
    LL N,K;
    cin >> N >> K;

    //calc
    LL ans=0;
    LL b;
    for(b=K+1; b<=N; b++){
        ans+=(b-K)*(N/b);
        ans+=max(N%b-(K-1LL),0LL);
    }
    if(K==0){
        ans-=N;
    }

    //output
    cout << ans << endl;
    system("pause");
    return 0;
}