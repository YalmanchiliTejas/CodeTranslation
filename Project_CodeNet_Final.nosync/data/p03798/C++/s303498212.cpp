#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long int i=0;i<n;++i)
typedef long long int ll;

int main(){

    int n;
    cin >> n;
    string s;
    cin >> s;

    s=s.back()+s+s[0];//1~nまで

    string c[4];

    if(s[1]=='o'){
        c[0]="SSS";
        c[1]="WSW";
        c[2]="SWW";
        c[3]="WWS";
        for(int i=0;i<4;i++){
            for(int j=2;j<=n;j++){
                if(c[i][j]=='S'){
                    if(s[j]=='o'){
                        c[i].push_back(c[i][c[i].size()-2]);
                    }else{
                        if(c[i][c[i].size()-2]=='S'){
                            c[i].push_back('W');
                        }else{
                            c[i].push_back('S');                            
                        }
                    }
                }else{
                    if(s[j]=='o'){
                        if(c[i][c[i].size()-2]=='S'){
                            c[i].push_back('W');
                        }else{
                            c[i].push_back('S');                            
                        }
                    }else{
                        c[i].push_back(c[i][c[i].size()-2]);
                    }
                }
            }
        }
    }else{
        c[0]="SSW";
        c[1]="WSS";
        c[2]="SWS";
        c[3]="WWW";
        for(int i=0;i<4;i++){
            for(int j=2;j<=n;j++){
                if(c[i][j]=='S'){
                    if(s[j]=='o'){
                        c[i].push_back(c[i][c[i].size()-2]);
                    }else{
                        if(c[i][c[i].size()-2]=='S'){
                            c[i].push_back('W');
                        }else{
                            c[i].push_back('S');                            
                        }
                    }
                }else{
                    if(s[j]=='o'){
                        if(c[i][c[i].size()-2]=='S'){
                            c[i].push_back('W');
                        }else{
                            c[i].push_back('S');                            
                        }
                    }else{
                        c[i].push_back(c[i][c[i].size()-2]);
                    }
                }
            }
        }
    }   

    for(int i=0;i<4;i++){
        if(c[i][0]==c[i][c[i].size()-2]&&c[i][1]==c[i].back()){
            //cout << c[i][0] << " " << c[i].back() <<endl;
            c[i].erase(c[i].begin());
            c[i].pop_back();
            cout << c[i]<<endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}