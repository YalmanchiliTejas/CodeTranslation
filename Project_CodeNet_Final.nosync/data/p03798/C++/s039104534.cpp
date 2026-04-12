#include <bits/stdc++.h>
using namespace std;
int N;
string S;
string animal;  // S:羊 W:狼 とした動物列を文字列として表現
bool same(int index) {
    if((animal[index] == 'S' and S[index] == 'o')
     or (animal[index] == 'W' and S[index] == 'x')) return true; // 両隣は同じ
    else return false;  // 両隣は異なる
}
bool decide_sheep_or_wolf() {
    for(int i = 1; i < N-1; i++) {
        if(same(i)) {
            animal += animal[i-1];
        }
        else {
            animal += (animal[i-1] == 'S' ? 'W' : 'S'); // 逆
        }
    }

    // 矛盾
    if(same(0) != (animal[N-1] == animal[1])) return false;
    if(same(N-1) != (animal[N-2] == animal[0])) return false;
    return true;
}
int main() {
    cin >> N;
    cin >> S;
    // 初めの2つの動物を決めるとoxの情報から芋づる式に決まっていく
    // 矛盾が無いかをそれぞれについて調べてなければ終わり
    // 答えがなければ-1
    vector<string> a = { "SS", "SW", "WS", "WW" };
    for(int i = 0; i < 4; i++) {
        animal = a[i];
        if(decide_sheep_or_wolf()) {
            cout << animal << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
