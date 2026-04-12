#include <bits/stdc++.h>
using namespace std;

int n,m,r=0;
vector<vector<int>> path1;
vector<vector<int>> path2;

void cal(int b,vector<int> count){
    count.push_back(b);
    for(int i=0;i<path1.at(b).size();i++){
        for(int j=0;j<count.size();j++){
            if (count.at(j) == path1.at(b).at(i)){
                goto label;
            }
        }
        cal(path1.at(b).at(i), count);
        label:;
    }
    for(int i=0;i<path2.at(b).size();i++){
        for(int j=0;j<count.size();j++){
            if (count.at(j) == path2.at(b).at(i)){
                goto label2;
            }
        }
        cal(path2.at(b).at(i), count);
        label2:;
    }

    if (count.size() == n){
        r++;
        return;
    }
    return;
}

int main() {
    cin >> n >> m;
    path1.resize(n);
    path2.resize(n);
    vector<vector<int>> path_tmp(m);
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            int tmp;
            cin >> tmp;
            path_tmp.at(i).push_back(tmp-1);
        }
    }

    for(int i=0;i<m;i++){
        path1.at(path_tmp.at(i).at(0)).push_back(path_tmp.at(i).at(1));
        path2.at(path_tmp.at(i).at(1)).push_back(path_tmp.at(i).at(0));
    }

    vector<int> count;
    cal(0,count);
    printf("%d\n",r);
}
