#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main() 
{
  char a; cin >> a;
  if(a == 'a' || a == 'i' || a == 'u'|| a == 'e' || a == 'o')
    cout << "vowel" << endl;
  else cout << "consonant" << endl;
  system("pause");
}