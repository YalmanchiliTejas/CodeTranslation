#include <bits/stdc++.h>
using namespace std;

int flag[10][10];
int dx[] = {1,0};
int dy[] = {0,1};
int main()
{
    vector<string> vec;
    int H,W;cin >> H >> W;
    for(int a =0;a < H;a++){
        string str;cin >> str;
        vec.push_back(str);
    }
    std::queue<pair<int,int>> que;
    que.push(make_pair(0,0));
    for(int x = 0;x < W-1;x++){
        for(int y = 0;y < H-1;y++){
            if(vec.at(y).at(x) == '#' && vec.at(y+1).at(x) == '#' && vec.at(y).at(x+1) == '#'){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    for(int x = 1;x < W;x++){
        for(int y = 1;y < H;y++){
            if(vec.at(y).at(x) == '#' && vec.at(y-1).at(x) == '#' && vec.at(y).at(x-1) == '#'){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    while(!que.empty()){
        pair<int,int> p = que.front();
        que.pop();
        if(p.first == W-1&&p.second == H-1){
            cout<<"Possible"<<endl;
            return 0;
        }
        flag[p.first][p.second]=1;
        for(int index = 0;index < 2;index++){
            if(0<=p.first + dx[index] && p.first + dx[index]<=W-1 && 0<=p.second + dy[index] && p.second + dy[index]<= H-1){
                if(flag[p.first+dx[index]][p.second+dy[index]] == 0&& vec.at(p.second+dy[index]).at(p.first+dx[index]) == '#'){
                    que.push(make_pair(p.first+dx[index],p.second+dy[index]));
                }
            }
        }
    }
    cout<<"Impossible"<<endl;
    return 0;
}