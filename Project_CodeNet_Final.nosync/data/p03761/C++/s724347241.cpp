#include <bits/stdc++.h>

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VS = vector<string>;
using PII = pair<int, int>;
using VPII = vector<PII>;

#define sz(var) (int)var.size()
#define REP(var, start, end) for(int var = start; var < (int)end; ++var)

/*
    problem : http://abc058.contest.atcoder.jp/tasks/arc071_a
    들어오는 n개의 string으로 만들 수 있는 글자 중 가장 긴 것중 사전순으로 가장 작은것을 출력
*/
int n;
const int Alphabet = 26;
VVI A;
string solve()
{
    REP(i, 0, n)
    {
        string s;
        cin >> s;

        for(auto c : s)
            ++A[i][c - 'a'];
    }

    string ans;
    REP(i, 0, Alphabet)
    {
        int cnt = 0, numChars = INT_MAX;
        REP(j, 0, n)
            if(A[j][i] != 0)
            {
                numChars = min(numChars, A[j][i]);
                ++cnt;
            }
        
        if(cnt == n)
            while(numChars--)
                ans += (char)i + 'a';
    }

    return ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("tmp.in", "r", stdin);
//	freopen("tmp.out", "w", stderr);
#endif
    cin >> n;

    A = VVI(n, VI(Alphabet, 0));

    cout << solve() << endl;

	return 0;
}