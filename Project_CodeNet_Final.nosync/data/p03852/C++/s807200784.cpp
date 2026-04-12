#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cctype>
#define rep(i, m, n) for(int i = m;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define ll long long
#define ull unsigned long long
#define push(a) push_back(a)
#define pop(a) pop_back(a)
#define debug(x) cout<<#x<<": "<<x<<endl
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
  char c;
  cin >> c;
  if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
    cout << "vowel" << endl;
  }else{
    cout << "consonant" << endl;
  }
}
