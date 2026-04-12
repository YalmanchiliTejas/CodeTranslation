// ===========================================
// 20.02.27
// 
// 
// ===========================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ET "\n"
#define CLR(arr) memset(arr, 0, sizeof(arr))
#define PAIR pair<int, int>
const ll INF = 1LL << 50;


int main(){
    
    ios::sync_with_stdio(false); cin.tie(0);
    
    const int MAX = 200020;
    
    int arr[MAX];
    int arc[MAX];
    
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arc[i] = arr[i];
    }
    
    sort(arr + 1, arr + n + 1, greater<int>());
    int mid = n/2;
    
    for(int i = 1; i <= n; i++){
        if(arc[i] < arr[mid]) 
            cout << arr[mid] << ET;
        else
            cout << arr[mid+1] << ET;
        
    }
    
}

