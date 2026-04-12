#include <bits/stdc++.h>
#define ll long long
#define INF INT_MAX 
#define mod 1000000007
using namespace std;
int main(){
    int N;
    cin >> N;
    int H[N];
    for(int i=0;i<N;i++){
        cin >> H[i];
    }
    int ans=0;
    int maxH=0;
    for(int i=0;i<N;i++){
        if(H[i]>=maxH){
            maxH = H[i];
            ans++;
        }
    }
    cout << ans << endl;
}