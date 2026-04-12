#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod=1e9+7;

vector<vector<int>> to(10);

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<int> num;
    for(int i = 0; i < n; i++){
        num.push_back(i);
    }
    int sam = 1;
    for(int i = 1; i < n; i++){
        sam *= i;
    }
    int cnt = 0;

    for(int i = 0; i < sam; i++){
        for(int i = 0; i < n-1; i++){
            bool flag = false;

            for(int j = 0; j < to[num[i]].size(); j++){
                if(i != 0 && to[num[i]][j] == num[i-1]) continue;
                if(to[num[i]][j] == num[i+1]) flag = true;
            }
            if(!flag) break;
            if(i == n-2) cnt++;
        }
        next_permutation(num.begin()+1,num.end());
    }

    cout << cnt << endl;

}