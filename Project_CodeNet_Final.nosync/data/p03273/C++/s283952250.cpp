#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<utility>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

using ll = long long;

void read();
template<typename First, typename... Rest> void read(First& first, Rest&... rest);
void write();
template<typename First, typename... Rest> void write(First first, Rest... rest);
template<typename T> void write_vec(vector<T>& v, char divider);

int main(){
    int H, W;
    read(H, W);
    vector<string> a(H);
    for(int i = 0; i < H; i++){
        read(a[i]);
    }
    int nH = H;
    int nW = W;
    int i = 0;
    while(i < nH){
        bool f = true;
        for(int j = 0; j < nW; j++){
            if(a[i][j] == '#') f = false;
        }
        if(f){
            for(int k = i; k < nH - 1; k++){
                for(int j = 0; j < nW; j++){
                    a[k][j] = a[k + 1][j];
                }
            }
            nH--;
        }
        else i++;
    }
    int j = 0;
    while(j < nW){
        bool f = true;
        for(int i = 0; i < nH; i++){
            if(a[i][j] == '#') f = false;
        }
        if(f){
            for(int k = j; k < nW - 1; k++){
                for(int i = 0; i < nH; i++){
                    a[i][k] = a[i][k + 1];
                }
            }
            nW--;
        }
        else j++;
    }
    for(int i = 0; i < nH; i++){
        for(int j = 0; j < nW; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}

//配列以外の入力を受け取る
void read(){

}
template<typename First, typename... Rest>
void read(First& first, Rest&... rest){
    cin >> first;
    read(rest...);
}
//
//配列以外を出力する
void write(){

}
template<typename First, typename... Rest>
void write(First first, Rest... rest){
    cout << first << " ";
    write(rest...);
}
//
//配列を区切って出力する
template<typename T>
void write_vec(vector<T>& v, char divider){
    for(size_t i = 0; i < v.size(); i++){
        cout << v[i] << divider;
    }
}
//