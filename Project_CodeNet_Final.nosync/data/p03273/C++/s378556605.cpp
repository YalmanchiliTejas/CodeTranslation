#include <iostream>
#include <vector>

using namespace std;

int main(){
    int h,w;
    char c;
    cin >> h >> w;

    vector<vector<int>>v(h+1,vector<int>(w+1));

    for(int i = 0;i < h;i++){
        int count = 0;
        for(int j = 0;j < w;j++){
            cin >> c;
            if(c == '.')
                v[i+1][j+1] = 0;
            else{
                v[i+1][j+1] = 1;
                v[i+1][0]++;
                v[0][j+1]++;
            }
        }
    }


    for(int i = 0;i < h;i++){
        bool flag = false;
        for(int j = 0;j < w;j++){
            if(v[i+1][0] == 0){
                flag = true;
                break;
            }
            else if(v[0][j+1] != 0)
                if(v[i+1][j+1] == 0)
                    cout << '.';
                else 
                    cout << '#';
        }
        if(!flag)cout << endl;
    }


    return 0;
}