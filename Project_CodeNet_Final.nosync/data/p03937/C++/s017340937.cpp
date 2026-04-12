#include <iostream>
using namespace std;


int main(){
    char banmen[12][12]={};
    int H,W;
    string answer={};

    cin >> H >> W;
    for(int i=1;i<=H;i++){
        for(int t=1;t<=W;t++){
            cin >> banmen[i][t];
        }
    }
  
    for(int i=1;i<=H;i++){
        for(int t=1;t<=W;t++){
            if(banmen[i][t]=='#'){
                //cout << i << "," << t << endl;
                if(banmen[i-1][t+1]=='#'){
                    answer="Impossible";
                    goto end;
                }else {answer="Possible";

                }
            }else{}
        }
    }
    
    
    end:
    cout << answer << endl;
    
    
    return 0;
}
