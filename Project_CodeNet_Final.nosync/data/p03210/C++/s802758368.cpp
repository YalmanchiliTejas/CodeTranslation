#include<bits/stdc++.h>
#define MIN -1000000
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
bool visited[100005];
const int max_N=1e5+10;
int H,W,h,w;
int board[105][105];
int mxindex,mxchain=0;
int X;
int main(void)
{
  cin >> X;
  if(X ==3 || X==5 || X==7) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
