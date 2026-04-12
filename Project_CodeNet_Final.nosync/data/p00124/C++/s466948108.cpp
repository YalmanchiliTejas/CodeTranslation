#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct P{
    string name;
    int win;
    int lose;
    int even;
    int total;
    static bool more (const P& left,const P& right){
        return left.total > right.total;
    }
};

int main(){
    int n;
    int cnt;
    bool b = false;
    while(1){
        cnt = 0;
        cin >> n;
        if(n == 0) break;
        if(b) cout << endl;
        else b = true;
        vector <P> data;
        P tmp;
        for(int i=0;i<n;i++){
            cin >> tmp.name >> tmp.win >> tmp.lose >> tmp.even;
            tmp.total = tmp.win*3 + tmp.even;
            data.push_back(tmp);
            cnt++;
        }
        sort(data.begin(),data.end(),P::more);
        for(int i=0;i<cnt;i++){
            cout << data[i].name << "," << data[i].total << endl;
        }
    }
}