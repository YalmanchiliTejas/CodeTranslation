#include <bits/stdc++.h>

#define foreach(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define BETWEEN(a, x, b) (a<=x&&x<b)

using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

  int n;cin>>n;
  int h[30];
  for(int i=0;i<n;i++)cin>>h[i];

  int res = 0;
  for(int i=0;i<n;i++){
    bool ok = true;
    for(int j=0;j<i;j++){
      if(h[j]>h[i])ok=false;
    }
    if(ok)res++;
  }
  cout<<res<<endl;

  return 0;
}
