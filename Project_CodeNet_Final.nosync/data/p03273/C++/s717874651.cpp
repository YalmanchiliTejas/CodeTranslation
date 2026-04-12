#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
        int h,w;
        vector< vector<char> > a;

        cin >> h >> w;
        a.resize(h);
        for (int i=0; i<h; i++){
                a[i].resize(w);
                for(int j=0; j<w; j++){
                        cin >> a[i][j];
                }
        }
        vector<bool> hq(h,false);
        vector<bool> wq(w,false);

        for (int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                        if(a[i][j]=='#') {
                                hq[i]=true;
                                break;
                        }
                }
        }
        for (int j=0; j<w; j++){
               for(int i=0; i<h; i++){
                      if(a[i][j]=='#'){
                            wq[j]=true;
                            break;
                      }
               }
        }
        for (int i=0; i<h; i++){
                if (hq[i]){
                    for(int j=0; j<w; j++){
                            if (wq[j]){
                                cout << a[i][j];
                            }
                    }
                    cout << endl;
                }
        }
}
