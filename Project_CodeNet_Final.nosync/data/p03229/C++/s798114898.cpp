#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N;
    cin >> N;
    ll A[N];
        ll i;
    for(i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A,A+N);
    ll sum=0,sum1=0;

    if(N%2==0){
        for(i=0;i<N/2-1;i++){
            sum+=2*(A[N-1-i]-A[i]);
        }
        sum+=A[N/2]-A[N/2-1];
    }else {
        for(i=0;i<N/2;i++){
            sum-=2*A[i];
            sum1+=2*A[N-i-1];
        }
        for(i=0;i<N/2-1;i++){
            sum+=2*A[N-i-1];
            sum1-=2*A[i];
        }
        sum+=A[N/2]+A[N/2+1];
        sum1-=A[N/2]+A[N/2-1];
    }
    cout << max(sum,sum1) << endl;
    return 0;
}
