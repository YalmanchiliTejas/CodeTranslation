//B-Great Ocean View

#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int H[N];
    int CanView=1;
    
    for(int i=0;i<N;++i){
        cin >> H[i];
    }
    
    for(int i=1;i<N;++i){
        int Point=H[i];
        bool Flag=true;
        for(int j=i;j>=0;--j){
            if(Point<H[j]){
                Flag=false;
                break;
            }
        }
        if(Flag){
            CanView++;
        } 
    }
    cout << CanView << endl;
    return 0;
}