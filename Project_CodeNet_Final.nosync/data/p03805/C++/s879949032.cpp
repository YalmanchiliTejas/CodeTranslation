#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,cnt;
    cnt = 0;
    int cnt2 = 0;
    int ans = 0;
    cin >> n >> m;
    vector<int> v(n);
    vector<vector<int>> s(m,vector<int>(2));
    for(int i=0;i<n;i++) v[i] = i+1;
    for(int i=0;i<m;i++){
        cin >> s[i][0] >> s[i][1];
    }
    do{
      for(int i=0;i<n-1;i++){
          for(int j = 0;j<m;j++){
              if((s[j][0] == v[i] && s[j][1] == v[i+1])or(s[j][0] == v[i+1] && s[j][1] == v[i]))cnt++;
          }
          if(cnt == 1)cnt2++;
          cnt = 0;
      }
      if(cnt2 == n-1 && v[0] == 1)ans++;
      cnt2 = 0;
    }while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}