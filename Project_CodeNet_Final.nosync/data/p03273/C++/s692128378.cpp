#include<bits/stdc++.h>
using namespace std;

#define ED return 0;
#define SORT(vec) sort(vec.begin(),vec.end());
#define DOUBLECHANGE(count) cout << setprecision(count);
#define REV(vec) reverse(vec.begin(),vec.end());
#define ipow(x,y) int(pow(x,y))
const long long mod = 1000000007;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> vec (H);
    vector<bool> Wtest (H,false);
    vector<bool> Htest (W,false);
    for(int i = 0;i < H;i++){
        cin >> vec.at(i);
        bool test = true;
        for(int j = 0;j < W;j++){
            if(vec.at(i).at(j) == '#'){
                test = false;
            }
        }
        if(test){
            Wtest.at(i) = true;
        }
    }
    for(int i = 0;i < W;i++){
        bool test = true;
        for(int j = 0;j < H;j++){
            if(vec.at(j).at(i) == '#'){
                test = false;
            }
        }
        if(test){
            Htest.at(i) = true;
        }
    }

    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            if(Htest.at(j) == false && Wtest.at(i) == false){
                cout << vec.at(i).at(j);
            }
        }
        if(Wtest.at(i) == false){
        cout << endl;
        }
    }
}
