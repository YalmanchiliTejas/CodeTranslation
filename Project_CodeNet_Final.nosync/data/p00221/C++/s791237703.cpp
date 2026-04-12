#include<bits/stdc++.h>

using namespace std;

string to_string(int N){
    stringstream ss;
    ss<<N;
    string ret;
    ss>>ret;
    return ret;
}

bool isCorrect(int n, string s)
{
    string solution;
    if (n % 3 == 0 && n % 5 == 0) solution = "FizzBuzz";
    else if (n % 3 == 0) solution = "Fizz";
    else if (n % 5 == 0) solution = "Buzz";
    else solution = to_string(n);
    return solution == s;
}

int main()
{
    int M, N;
    while (cin >> M >> N, N || M)
    {
        bool isExist[1000] = {};
        fill_n(isExist, 1000, true);
        int cnt = M, p = 0;
        for (int i = 1; i <= N; i++, p = (p + 1) % M)
        {
            while (!isExist[p]) p = (p + 1) % M;
            string s;
            cin >> s;
            if (!isCorrect(i, s))
            {
                isExist[p] = false;
                if (--cnt == 1)
                {
                    while (++i <= N) cin >> s;
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < M; i++)
        {
            if (isExist[i]) ans.push_back(i);
        }
        if (ans.size() == 0)
        {
            while (true) {}
        }
        printf("%d", ans[0] + 1);
        for (int i = 1; i < ans.size(); i++)
        {
            printf(" %d", ans[i] + 1);
        }
        puts("");
    }
    return 0;
}