#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Team{
    string name;
    int id;
    int point;
    bool operator <(const Team& r) const{
        return point == r.point ? id < r.id : point > r.point;
    }
};


int main(){
    string name;
    int n, a, b, c, i = 0;
    while(cin >> n, n){
        if(i) cout << endl;
        vector< Team > v(n);
        for(i = 0; i < n; i++){
            cin >> name >> a >> b >> c;
            v[i].id = i;
            v[i].name = name;
            v[i].point = a * 3 + c;
        }
        sort(v.begin(), v.end());
        for(i = 0; i < n; i++){
            cout << v[i].name << "," << v[i].point << endl;
        }
    }
    return 0;
}