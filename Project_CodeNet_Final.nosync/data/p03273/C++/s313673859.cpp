#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;

    vector<string> a;
//    vector<vector<string>> a(H, vector<string>(W));

    vector<int> height(H,1);
    vector<int> width(W,1);

    for (int i = 0; i < H; i++)
    {
        for (int k = 0; k < W; k++)
        {
            string b;
            cin >> b;
            a.push_back(b);
            if(a[i].substr(k,1) == "#"){
                height[i] = height[i] * 0;
                width[k] = width[k] * 0;
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        int flag = 1;
        for (int k = 0; k < W; k++)
        {
            if(height[i]!=1 && width[k] != 1){
                flag = 0;
                cout << a[i].substr(k,1);
            }
        }
        if(flag == 0) cout << endl;
        flag = 1;
    }
}