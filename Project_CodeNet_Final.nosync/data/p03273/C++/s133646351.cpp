#include <bits/stdc++.h>
using namespace std;
int main(void){
    int h,w;
    cin>>h>>w;
    std::vector<vector<char>> vec(h,vector<char>(w));
    char c;
    for (int i=0;i<h;i++) {
        int count_yoko=0;
        for (int j=0;j<w;j++) {
            cin>>c;
            if (c=='.') {
                count_yoko++;
            }
            vec.at(i).at(j)=c;
            if (count_yoko==w) {
                for (int k=0;k<w;k++) {
                    vec.at(i).at(k)='*';
                }
            }
        }
    }
    for (int l=0;l<w;l++) {
        int count_tate=0;
        for (int m=0;m<h;m++) {
            if (vec.at(m).at(l)=='.'||vec.at(m).at(l)=='*') {
                count_tate++;
            }
            if (count_tate==h) {
                for (int n=0;n<h;n++) {
                    vec.at(n).at(l)='*';
                }
            }
        }
    }
    for (int hoge=0;hoge<h;hoge++) {
        int count=0;
        for (int piyo=0;piyo<w;piyo++) {
            if (vec.at(hoge).at(piyo)!='*') {
                cout<<vec.at(hoge).at(piyo);
            } else {
                count++;
            }
        }
        if (count!=w) {
            cout<<endl;
        }
    }
}