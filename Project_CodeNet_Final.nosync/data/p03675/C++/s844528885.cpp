#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <unordered_map>
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int arr[200010];
bool vis[200010];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    int idx = n + 1;
    bool reached = false;
    bool da = false;
    while(true){
        vis[idx] = true;
        
        if(idx - 2 >= 0){
            idx -= 2;
        }
        else{
            break;
        }
        if(vis[idx])continue;
        cout << arr[idx] << " " ;

    }
    idx = 0;
//    cout << arr[idx] << " ";
    if(n % 2 == 1)idx ++;
    while(idx < n){
        cout << arr[idx] << " ";
        idx += 2;
    }
    return 0;
}
