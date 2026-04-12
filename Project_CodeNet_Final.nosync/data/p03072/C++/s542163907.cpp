#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
    int  N;
    cin >> N;
    vector<int> Ryokan(N+1,0);
    for(int i=1; i<=N; i++) cin >> Ryokan[i];
    
    int ans_count=1;
    int max_high=Ryokan[1];
    for(int i=2; i<=N; i++){
        if(max_high <= Ryokan[i]){
            ans_count++;
            max_high = Ryokan[i];
        }
        
    }
    cout << ans_count << endl;
    
    /*
    for(int x:Ryokan){
        cout << x <<" ";
    }
    */
}
