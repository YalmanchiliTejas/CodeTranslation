#include<iostream>
#include<string>
using namespace std;
 
int main(){
    string N;
    int K;
    cin >> N;
    cin >> K;
    
    int n[N.size()];
    long ones[101][2][101]={}; // #digit, smaller flag, #nonzero
 
    long ans;
 
    for(int i=0; i<N.size(); i++){
        n[i] = (int) N[i] - '0';
        //cout << n[i] << endl;
    }
 
    ones[0][0][0] = 1;

    for(int i=0; i<N.size(); i++){
        for(int smaller=0; smaller<2; smaller++){
            for(int j=0; j<=K; j++){
                for(int x=0; x<= (smaller ? 9 : n[i]); x++){
                    if( x==0 ){
                        ones[i+1][ smaller | (x<n[i]) ][j] += ones[i][smaller][j];
                    }else{
                        ones[i+1][ smaller | (x<n[i]) ][j+1] += ones[i][smaller][j];                        
                    }
 
                }
                //cout << "total: ones[ " << i+1 << " ][ " <<  smaller  << " ][ " << j << " ] = " << ones[i+1][ smaller ][j] << endl; 
            }
        }
    }
 
    ans += ones[N.size()][0][K] + ones[N.size()][1][K];
 
    cout << ans << endl;
 
    return 0;
}