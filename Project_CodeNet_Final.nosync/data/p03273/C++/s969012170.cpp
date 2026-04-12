#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <map>
#include <set>
#define ull unsigned long long
#define ll long long
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    string t(w,'.'),s;
    vector<string> q;
    for(int i=0;i<h;i++){
        cin >> s;
        if(s==t){continue;}
        else q.emplace_back(s);
    }

    h=q.size();
    vector<int> p;
    int cnt=0;
    for(int i=0;i<w;i++){
        cnt=0;
        for(int j=0;j<h;j++){
            if(q[j][i]=='#'){
                break;
            }
            cnt++;
        }
        if(cnt==h){
            p.emplace_back(0);
        }
        else p.emplace_back(1);
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(p[j]==0){continue;}
            else cout << q[i][j];
        }
        cout << endl;
    }

    return 0;
}