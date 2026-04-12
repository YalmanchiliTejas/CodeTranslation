#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include <algorithm> 
using namespace std;

# define p(s) std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;

int main()
{
    int h,w;cin >> h >> w ;

    char a[100][100];

    int del_h_c=0;
    for(int i=0;i<h;i++){
        string s;cin >> s;


        if(s.find('#')==string::npos) {
            del_h_c++;
            continue;
        }
        for(int j=0;j<s.size();j++){
            a[(i-del_h_c)][j] = s.at(j);
        }
    }

    bool isShow_j[100];
    for(int j=0;j<w;j++){
        isShow_j[j]=true;
        if(a[0][j]=='.'){
            isShow_j[j]=false;
            for(int i=1;i<h-del_h_c;i++){
                if(a[i][j]=='#'){
                    isShow_j[j]=true;
                    break;
                }
            }
        }
    }

    for(int i=0;i<h-del_h_c;i++){
        for(int j=0;j<w;j++){
            if(isShow_j[j]) cout << a[i][j];
        }
        cout << endl;
    }
} 