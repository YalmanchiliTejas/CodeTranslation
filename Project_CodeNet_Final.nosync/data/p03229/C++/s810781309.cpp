#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int N; cin >> N;
    int a[N];
    for(int i=0;i<N;i++) cin >> a[i];
    sort(a,a+N,greater<int>());
    ll ans1=0,ans2=0;
    if(N%2){
        for(int i=0;i<(N-1)/2-1;i++){
            ans1+=2*a[i];
        }
        for(int i=0;i<(N-1)/2;i++){
            ans2+=2*a[i];
        }
        ans1+=a[(N-1)/2-1]+a[(N-1)/2];
        ans2-=a[(N-1)/2]+a[(N-1)/2+1];
        for(int i=(N-1)/2+1;i<N;i++){
            ans1-=2*a[i];
        }
        for(int i=(N-1)/2+2;i<N;i++){
            ans2-=2*a[i];
        }
        cout << max(ans1,ans2) << endl;
    }else{
        for(int i=0;i<N/2-1;i++){
            ans1+=2*a[i];
        }
        ans1+=a[N/2-1]-a[N/2];
        for(int i=N/2+1;i<N;i++){
            ans1-=2*a[i];
        }
        cout << ans1 << endl;
    }
    

    

}