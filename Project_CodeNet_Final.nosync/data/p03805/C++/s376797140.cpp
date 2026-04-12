#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;

int matrix[8][8];

bool visit[8] = {false};

void init(){
    for(int i = 0; i < n; i++){
        visit[i] = false;
    }
}

int main(){
    
    cin >> n >> m;

    

    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            matrix[y][x] = 0;
        }
    }

    int a, b;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        matrix[a-1][b-1] = 1;
        matrix[b-1][a-1] = 1;
    }

    vector<int> v;
    for(int i = 0; i < n; i++){
        v.push_back(i);
    }
    sort(v.begin(), v.end());

    int count = 0;

    do {
        if(v[0] != 0){
            continue;
        }

        bool flag = true;

        for(int i = 0; i < n; i++){
            if(i == n - 1){
                continue;
            }
           
            int now = v[i];
            int next = v[i+1];

            if(matrix[now][next] != 1){
                flag = false;
                break;
            } 
        }
        if(flag == true){
            count++;
        }
    } while(next_permutation(v.begin(), v.end()));

    printf("%d\n", count);

    return 0;
}