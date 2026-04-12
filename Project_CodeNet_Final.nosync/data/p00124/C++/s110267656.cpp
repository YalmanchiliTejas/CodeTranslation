#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define loop(i,a,b) for(int i=(a); i<int(b); i++)
#define rep(i,b) loop(i,0,b)
#define all(c) (c).begin(), (c).end()

struct team{
    string name;
    int score, id;
};

int main(){
    bool begin = true;
    int n;

    while(cin >> n && n){
        if(!begin) puts("");
        begin = false;

        vector<team> rs(n);
        rep(i,n){
            int a, b, c;
            cin >> rs[i].name >> a >> b >> c;
            rs[i].score = a*3 + c;
            rs[i].id = i;
        }

        sort(all(rs),[](const team& a, const team& b){
                if(a.score != b.score) return a.score > b.score;
                else return a.id < b.id;
            });

        rep(i,n){
            cout << rs[i].name << "," << rs[i].score << endl;
        }
    }

}