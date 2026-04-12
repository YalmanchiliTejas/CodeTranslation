#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int judge(int n){
  int max=-1, min=1001, sum=0;
  vi s(n);
  rep(i, n){
    cin >> s[i];
    sum+=s[i];
    if(s[i]>max)max=s[i];
    if(s[i]<min)min=s[i];
  }
  return (sum-max-min)/(n-2);
}

int main(){
  int cnt=0;
  vi ans(20);
  rep(i, 20){
    int n;
    cin >> n;
    if(n==0)break;
    ans[i]=judge(n);
    cnt++;
  }

  rep(i, cnt){
    if(ans[i]==-1)break;
    cout << ans[i] << endl;
  }

  return 0;
}
