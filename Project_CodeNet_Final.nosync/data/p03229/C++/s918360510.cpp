#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
using ll = long long;
using namespace std;

int const MOD = 1e9 + 7;
int a[100010];
int arr[100010];
int main(void)
{
    int N; cin >> N;
    for(int i=0; i<N; ++i) cin >> a[i];
    
    sort(a, a+N);
    if(N%2==0){
        for(int i=0; i<N/2; ++i){
            if(i==0) arr[N/2-1] = a[0];
            else{
                if(N/2-2*i-1>=0) arr[N/2-2*i-1] = a[2*i];
                if(N/2+2*i-1<N) arr[N/2+2*i-1] = a[2*i-1];
            }
        }
        for(int i=0; i<N/2; ++i){
            if(i==0) arr[N/2] = a[N-1];
            else{
                if(N/2-2*i>=0) arr[N/2-2*i]= a[N-1-2*i+1];
                if(N/2+2*i<N) arr[N/2+2*i]= a[N-1-2*i]; 
            }
        }
        ll ans=0;
        for(int i=1; i<N; ++i){
            ans += abs(arr[i]-arr[i-1]);
        }
        cout << ans << endl;
    }else{
        ll ans1=0;
        ll ans2=0;
        arr[N/2] = a[0];
        for(int i=1; i<=N/2; ++i){
            if(N/2-2*i>=0) arr[N/2-2*i] = a[2*i];
            if(N/2+2*i<N) arr[N/2+2*i] = a[2*i-1];
        }
        
        for(int i=1; i<=N/2; ++i){
            if(N/2-2*(i-1)-1>=0) arr[N/2-2*(i-1)-1]= a[N-1-2*(i-1)];
            if(N/2+2*(i-1)+1<N) arr[N/2+2*(i-1)+1]= a[N-1-2*(i-1)-1]; 
        }
        for(int i=1; i<N; ++i){
            ans1 += abs(arr[i]-arr[i-1]);
        }
        
        
        arr[N/2] = a[N-1];
        for(int i=1; i<=N/2; ++i){
            if(N/2-2*i>=0) arr[N/2-2*i]= a[N-1-2*i];
            if(N/2+2*i<N) arr[N/2+2*i]= a[N-1-2*i+1]; 
        }
        
        for(int i=1; i<=N/2; ++i){
            if(N/2-2*(i-1)-1>=0)arr[N/2-2*(i-1)-1] = a[2*(i-1)];
            if(N/2+2*(i-1)+1<N) arr[N/2+2*(i-1)+1] = a[2*(i-1)+1];
        }
        for(int i=1; i<N; ++i){
            ans2 += abs(arr[i]-arr[i-1]);
        }
        cout << max(ans1, ans2) << endl;
    }
    
    return 0;
}