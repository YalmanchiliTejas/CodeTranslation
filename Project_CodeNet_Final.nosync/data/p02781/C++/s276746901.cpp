#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<array>

using namespace std;

int ctoi( char& c ){
    return ( c - 48);
}

int func(int K, string N){

    int ans = 0;
    
    if(K == 1){

        if(N[0] == '0'){
            if(N.length() == 1){
                return 0;
            }else{
                return func(1, N.substr(1));
            }
        }else{
            ans = ctoi(N[0]) + (N.length() - 1) * 9;
            return ans;
        }

    }else if(K == 2){

        if(N[0] == '0'){
            if(N.length() <= 2){
                return 0;
            }else{
                return func( 2, N.substr(1));
            }        
        }else{
            if(N.length() < 2){
                return 0;
            }        

            int t = N.length() - 1; 
            ans += 81 * t * ( t - 1) / 2 ;
            ans += 9 * ( ctoi(N[0]) - 1 ) * t; 
            ans += func( 1, N.substr(1) );

            return ans;            
        }

    }else if(K == 3){

        if(N[0] == '0'){
            if(N.length() <= 3){
                return 0;
            }else{
                return func( 3, N.substr(1));
            }        
        }else{
            if(N.length() < 3){
                return 0;
            }        

            int t = N.length() - 1;
            ans += 729 * t * ( t - 1 ) * (t - 2) / 6;
            ans += 81 * ( ctoi(N[0]) - 1 ) * t * ( t - 1 ) / 2; 
            ans += func( 2, N.substr(1) );

            return ans;            
        }
        
    }
}   

int main(){

    string N;
    int K;
    cin >> N;
    cin >> K;

    cout << func( K, N ) << endl; 
    return 0;
}
