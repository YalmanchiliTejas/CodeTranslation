#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

int a[15][15];

int id[15][15];

typedef pair<int, int> pii;

vector<pair<pii, int> > edges;

int d[15][15];

int A, B;

int idX(int i){
    return i + 1;
}

int idY(int i){
    return 202 - i;
}

int c[105][105];

int main(){
    cin >> A >> B;
    for(int i = 1;i <= A;i++){
        for(int j = 1;j <= B;j++){
            scanf("%d", &d[i][j]);
        }
    }
    for(int i = 0;i <= 100;i++){
        for(int j = 0;j <= 100;j++){
            int mx = 0;
            for(int i1 = 1;i1 <= A;i1++){
                for(int j1 = 1;j1 <= B;j1++){
                    int len = i1 * i + j1 * j;
                    mx = max(mx, d[i1][j1] - len);
                }
            }
            c[i][j] = mx;
        }
    } 
    bool flag = true;
    for(int i1 = 1;i1 <= A;i1++){
        for(int j1 = 1;j1 <= B;j1++){
            bool find = false;
            for(int i = 0;i <= 100;i++){
                for(int j = 0;j <= 100;j++){
                    if(i * i1 + j * j1 + c[i][j] == d[i1][j1])
                        find = true;
                }
            }
            flag &= find;
        }
    }
    if(flag){
        puts("Possible");
        for(int i = 1;i <= 100;i++){
            edges.push_back(make_pair(make_pair(i, i + 1), -2));
        }
        for(int i = 102;i <= 201;i++){
            edges.push_back(make_pair(make_pair(i, i + 1), -1));
        }
        for(int i = 0;i <= 100;i++){
            for(int j = 0;j <= 100;j++){
                if(c[i][j] <= 100)
                    edges.push_back(make_pair(make_pair(idX(i), idY(j)), c[i][j]));
            }
        }
        cout << 202 << " " << edges.size() << endl;
        for(auto e : edges){
            pii p = e.first;
            int val = e.second; 
            if(val == -2){
                cout << p.first << " " << p.second << " X" << endl;
            }else if(val == -1){
                cout << p.first << " " << p.second << " Y" << endl;
            }else{
                cout << p.first << " " << p.second << " " << val << endl;
            }
        }
        cout << 1 << " " << 202 << endl;
    }else{
        puts("Impossible"); 
    }
    return 0;
}
