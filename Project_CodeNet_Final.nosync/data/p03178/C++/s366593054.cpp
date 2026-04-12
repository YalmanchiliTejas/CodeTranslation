#include <iostream>
#include <map>
#include <algorithm>    
#include <vector>       
#include <set>
#include <utility>  
#include <cstring>
#include <stdio.h>
#include <limits.h>
#include <queue>
#include <algorithm> 
#define MAX_DOUBLE  40000000000.0 
#include <math.h> 
#include <unistd.h>

using namespace std;

long long mod = 1e9 + 7; 

long long res[10010][100];

int main(){
	string s;
	cin>>s;
	int d;
	cin>>d;
	
	int len = s.size();
	
	for(int i = 0; i < 10; i++){
		res[0][i%d] ++;
	}
	
	for(int i = 1; i <= len; i++ ){
		for(int j = 0; j < d; j++){
			for(int z = 0; z < 10; z++){
				res[i][(j+z)%d] += res[i-1][j];
				res[i][(j+z)%d] %= mod;
			}
		}
	}
	
	long long ans = 0;
	
	int bla = 0;
	
	for(int i = 0; i<len; i++){
		if(i == len-1){
			int s_num = s[i] - '0';
			for(int q = 0; q<=s_num; q++){
				if((bla + q)%d == 0){
					ans +=1;
					ans %= mod; 
				}
			}
			
			break;
		}
		
		int s_num = s[i] - '0';
		for(int j = 0; j < s_num; j++){
			for(int cif = 0; cif < d; cif++){
				int tmp = j + bla + cif;				
				if(tmp % d == 0){
					ans += res[len-2-i][cif];
					ans %= mod; 
				}
				
			}
		}
		bla += s_num;
	}	

	cout<<(ans-1 + mod) % mod<<endl;	
	
		
}