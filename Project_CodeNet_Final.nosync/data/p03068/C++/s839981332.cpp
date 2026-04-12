#include <bits/stdc++.h>

#define foreach(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define BETWEEN(a, x, b) (a<=x&&x<b)

using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

  int n,k;cin>>n;string s;cin>>s;cin>>k;k--;
  for(int i=0;i<n;i++){
    if(s[i]==s[k])cout<<s[k];
    else cout<<'*';
  }
  cout<<endl;

  return 0;
}
