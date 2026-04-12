#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//#がある行・列だけ出力
//まず#の場所を取得
int main(){
    int H,W;
    cin >> H >> W;
    string masu[H];
    for(int i=0;i<H;i++) cin >> masu[i];

    vector<int> h;
    vector<int> w;

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(masu[i][j]=='#'){
                h.push_back(i);
                w.push_back(j);
            }
        }
    }

    sort(h.begin(),h.end());
    h.erase(unique(h.begin(),h.end()),h.end());

    sort(w.begin(),w.end());
    w.erase(unique(w.begin(),w.end()),w.end());

    typedef vector<int>::iterator itr;
    for(itr it=h.begin();it!=h.end();it++){
        for(itr it2=w.begin();it2!=w.end();it2++){
            cout << masu[*it][*it2];
        }
        cout << endl;
    }

    return 0;
}