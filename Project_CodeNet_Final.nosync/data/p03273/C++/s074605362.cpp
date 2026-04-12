#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> in(H);
    vector<bool> h(H, false);
    vector<bool> w(W, false);
    for(size_t i = 0; i < H; i++)
    {
        cin >> in[i];
    }
    for(size_t i = 0; i < H; i++)
    {
        for(size_t j = 0; j < W; j++)
        {
            if(in[i][j] == '#')
                h[i] = true;
        }
    }
    for(size_t i = 0; i < W; i++)
    {
        for(size_t j = 0; j < H; j++)
        {
            if(in[j][i] == '#')
                w[i] = true;
        }
    }
    vector<string> ret;
    for(size_t i = 0; i < H; i++)
    {
        if(!h[i])
            continue;
        ret.push_back("");
        for(size_t j = 0; j < W; j++)
        {
            if(w[j])
                ret.back() += in[i].substr(j,1);
        }
        
    }
    for(auto str : ret)
        cout << str << endl;
    return 0;
}