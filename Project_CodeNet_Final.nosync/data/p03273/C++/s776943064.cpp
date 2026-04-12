#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){

    int h,w;

    cin >> h >> w;

    vector<string> a(h);

    for(int i = 0;i < h; ++i){

        cin >> a[i];

        a[i] += "\n";

        if((int)a[i].find("#") == -1){

            a[i].erase(a[i].begin(),a[i].end());

        }
    }

    int n = w;

    for(int i = 0; i < n; ++i){

        for(int j = 0;j < w; ++j){

            bool b = true;

            for(int k = 0; k < h; ++k){

                if(a[k][j] == '#')b = false; 

            }

            if(b){

                for(int k = 0; k < h; ++k){

                    if(a[k].empty() == false){
                    
                        a[k].erase(a[k].begin() + j);

                    }

                }
                --w;
            }

        }

    }
    for(string i: a)cout << i;

    return 0;

}