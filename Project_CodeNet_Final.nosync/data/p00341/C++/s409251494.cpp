#include <iostream>
using namespace std;
int main(void){
    int a[110] = {0}; //辺の長さが同じものを格納する箱
    int p; //辺の長さ
    for(int i = 1; i <= 12; i++){
        cin >> p;
        a[p]++;
    }

    int count = 0; //4辺が等しければ１カウントする
    for(int i = 1; i <= 100; i++){
        if(a[i] == 4) count++;
        if(a[i] == 8) count += 2;
        if(a[i] == 12) count += 3;
    }
    if(count == 3) cout << "yes" << endl;
    else cout << "no" << endl;
}

