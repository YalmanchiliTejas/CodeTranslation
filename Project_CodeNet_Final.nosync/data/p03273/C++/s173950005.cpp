#include <bits/stdc++.h>

using namespace std;
char board[105][105];
bool deleted[105][105];
int n,m;
bool allWhiteRow(int curRow)
{
    for(int i = 1;i <= m;i++)
    {
        if(board[curRow][i] == '#')
            return false;
    }
    for(int i = 1;i <= m;i++)
        deleted[curRow][i] = true;
    return true;
}
bool allWhiteCol(int Col)
{
    for(int i = 1;i <= n;i++)
    {
        if(board[i][Col] == '#')
            return false;
    }
    for(int i = 1;i <= n;i++)
        deleted[i][Col] = true;
    return true;
}
int main()
{

    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        for(int j = 0;j < s.length();j++)
            board[i][j+1] = s[j];
    }
    for(int i = 1;i <= n;i++)
        allWhiteRow(i);
    for(int i = 1;i <= m;i++)
        allWhiteCol(i);
    for(int i = 1;i <= n;i++)
    {
        bool f = false;
        for(int j = 1;j <= m;j++)
        {
            if(deleted[i][j])
                continue;
            f = true;
            cout << board[i][j];
        }
        if(f)
        cout << endl;
    }
	return 0;
}
