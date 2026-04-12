#include <iostream>
#include <vector>

using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<bool>> mat(h, vector<bool>(w));
    for(int hi=0; hi<h; ++hi){
        for(int wi=0; wi<w; ++wi){
            char c;
            cin >> c;
            if(c=='.') mat[hi][wi]=true;
            else mat[hi][wi]=false;
        }
    }
    bool changed;
    do{
        changed=false;
        for(int hi=0; hi<h; ++hi){
            bool found=true;
            for(int wi=0; wi<w; ++wi){
                if(!mat[hi][wi]){
                    found=false;
                    break;
                }
            }
            if(found){
                --h;
                for(; hi<h; ++hi){
                    for(int wi=0; wi<w; ++wi){
                        mat[hi][wi]=mat[hi+1][wi];
                    }
                }
                changed=true;
                break;
            }
        }
        for(int wi=0; wi<w; ++wi){
            bool found=true;
            for(int hi=0; hi<h; ++hi){
                if(!mat[hi][wi]){
                    found=false;
                    break;
                }
            }
            if(found){
                --w;
                for(; wi<w; ++wi){
                    for(int hi=0; hi<h; ++hi){
                        mat[hi][wi]=mat[hi][wi+1];
                    }
                }
                changed=true;
                break;
            }
        }
    } while(changed);
    for(int hi=0; hi<h; ++hi){
        for(int wi=0; wi<w; ++wi){
            cout << (mat[hi][wi] ? '.' : '#');
        }
        cout << endl;
    }
    return 0;
}
