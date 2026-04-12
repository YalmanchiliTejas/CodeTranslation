#include <algorithm>
#include <cstdlib>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
int H,W;
bool is_there_black(const vector<char>& a){
        for(int i=0;i<a.size();i++)
        {
        if(a[i]=='#') return true;
        }
    return false;
}

int main(int argc, char const *argv[])
{
    cin>>H>>W;
    vector<vector<char>> a(H,vector<char>(W));
    vector<vector<char>> b(W,vector<char>(H));
    vector<bool> having_black_raw(H,false);
    vector<bool> having_black_col(W,false);

    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            cin>>a[h][w];
        }
    }
    
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            b[w][h]=a[h][w];
        }
    }
    for(int h=0;h<H;h++){
        having_black_raw[h]=is_there_black(a[h]);
    }
    for(int w=0;w<W;w++){
        having_black_col[w]=is_there_black(b[w]);
    }
    
    for(int h=0;h<H;h++){
        bool flag=false;
        for(int w=0;w<W;w++){
            if(having_black_raw[h]&&having_black_col[w]){
                cout<<a[h][w];
                flag=true;
            }
        }
        if(flag) cout<<endl;
    }
return 0;
}
