#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod107 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1)

const ll INF = 10010001010;
const int inf = 1000034000;
typedef vector<ll> vecl;
typedef vector<int> veci;
typedef tuple<string, int, int> TUP;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << fixed << setprecision(15);
    int N;
    cin >> N;
    vector<string> S(N);
    string ans;
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }
    for (char c = 'a'; c <= 'z';c++)
    {
        int M = 50000;
        for (int i = 0; i < N; i++)
        {

            int count = 0;
            for (int j = 0; j < S[i].size();j++)
            {
                if(c == S[i][j]){
                    count++;
                }
            }
            M = min(M,count);
        }
       // cout << M << endl;
        for (int i = 0; i < M; i++)
        {
            ans += c;
            
        }
    }
    cout << ans << endl;
}
