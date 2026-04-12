#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;bool way[9][9] = {false};
    int64_t ans = 0;
    cin >> n >> m;
    vector<int> a(30),b(30);
    for(int i = 0;i < m;i++){
        cin >> a[i] >> b[i];
        way[a[i]][b[i]] = true;
        way[b[i]][a[i]] = true;
    }
    vector<int> order(n);
    for(int i = 0;i < n;i++)order[i] = i+1;
    do{
        if(order[0] != 1)break;
        bool exist = true;
        for(int i = 1;i < n && exist;i++){
            if(!(way[order[i-1]][order[i]]))exist = false;
        }
        if(exist)ans++;
    }while(next_permutation(order.begin(),order.end()));
    std::cout << ans;
    return 0;
}