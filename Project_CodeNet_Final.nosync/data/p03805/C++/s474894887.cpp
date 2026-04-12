#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int ctoi(char);

//既にその頂点を使用しているかを格納するリスト
vector<int> used;

//接続状況を格納するリスト
vector<vector<int>> connect;

int N, M;

int dfs(int now, int depth)
{
    //使用済みであればreturn
    if(used[now])
    {
        return 0;
    }

    //depthがNであれば有効なパスであるから1を返す
    if(depth == N)
    {
        return 1;
    }
    //使用済みフラグを立てる
    used[now] = 1;
    int ans = 0;

    //全部の遷移先をチェックする
    for (int i=0; i<N; i++)
    {
        //nowから繋がっている頂点であれば, 遷移を移す
        if (connect[now][i])
        {
            ans += dfs(i, depth + 1);
        }
    }
    used[now] = 0;
    return ans;

}

int main()
{
    cin >> N >> M;
    vector<int> a(M), b(M);

    rep(i, M)
    {
        cin >> a.at(i) >> b.at(i);
        //1から始まると使いにくいので-1した数を格納するようにする
        a.at(i) -= 1;
        b.at(i) -= 1;
    }
    used = vector<int>(N, 0);
    connect = vector<vector<int>>(N, vector<int>(N, 0));
    rep(i, M)
    {
        connect.at(a.at(i)).at(b.at(i)) = 1;
        connect.at(b.at(i)).at(a.at(i)) = 1;
    }
    //0番から始まるパスの種類を列挙し, 出力する
    cout << dfs(0, 1) <<endl;

}

int ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return -1;
}
