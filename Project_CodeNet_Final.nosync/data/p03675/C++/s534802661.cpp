#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int ans[200005];
int arr[200005];
int main(){
    int n;cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int s = 0, e = n-1;
    int z= 0;
    for(int i = n-1 ; i >= 0; i--){
        if(z%2==1){
            ans[s]=arr[i];
            s++;
        }else{
            ans[e]=arr[i];
            e--;
        }
        z++;
    }
    reverse(ans,ans+n);
    for(int i= 0; i <n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}
