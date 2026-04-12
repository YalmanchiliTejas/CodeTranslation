#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int counter[26];
int temp_counter[26];

int main()
{
    int n;cin >> n;
    vector<string> ss(n);
    rep(i,n)
    {
        cin >> ss[i];
    }
    rep(i,n)
    {
        for (int i = 0; i < 26; i++)
        {
            temp_counter[i] = 0;
        }
        for (auto &&j : ss[i])
        {
            if(i==0)counter[j-'a']++;
            temp_counter[j-'a']++;
        }
        for (int  i = 0; i < 26; i++)
        {
            chmin(counter[i], temp_counter[i]);
        }
        
        
    }
    vector<char> ans;
    for(int i = 0; i< 26; i++)
    {
        int num = counter[i];
        while(num >0)
        {
            ans.push_back('a'+i);
            num--;
        }
    }
    for (auto &&i : ans)
    {
        cout << i ;
    }
    cout << endl;
}