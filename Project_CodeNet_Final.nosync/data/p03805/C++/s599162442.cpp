#include <bits/stdc++.h>
using namespace std;


// 入力 
int N,M;

//iとjがつながっているか
bool brg(int i,int j,vector<int> edge[]){
                  return  (find(edge[i].begin(), edge[i].end(), j) != edge[i].end());
}

int rec(int bit, int v,vector<int> edge[])
{
    int res=0;

   //初期値
    if (bit == (1<<v)) {
        return 1;
    }

    // bit の v を除いたもの
    int prev_bit = bit & ~(1<<v);

    for (int u = 0; u < N; ++u) {
        if (!(prev_bit & (1<<u))) continue; // u が prev_bit になかったらダメ

            res +=rec(prev_bit, u,edge) *brg(u,v,edge);
    }

    return res;
}




int main()
{
    // 入力
    cin >> N>>M;
    vector<int> edge[N];

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);              
    }


    cout << rec((1<<N)-1, 0 ,edge)<< endl;

}