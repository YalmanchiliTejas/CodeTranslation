#include<bits/stdc++.h>
using namespace std;

string str;
int n, vet[100009];
int main(){
	char mapa[] = {'A','S','W'};
	cin >> n >> str;
	for(int i1 = 1;i1<=2;i1++){
		bool f;
		for(int j1 = 1;j1<=2;j1++){
			vet[0] = i1;
			vet[1] = j1;
				
			for(int k = 1;k<n-1;k++){
				if(vet[k] == 1){
					if(str[k] == 'o')
						vet[k+1] = vet[k-1];
						
					else if(str[k] == 'x')
						vet[k+1] = 3-vet[k-1];
					
				}else{
					if(str[k] == 'x')
						vet[k+1] = vet[k-1];
					else
						vet[k+1] = 3-vet[k-1];
					
					}	
				}
			
			
			f = 1;
			for(int i =0;i<n;i++){
				if(vet[i] == 1){
					if(str[i] == 'o')
						f = f and (vet[(i-1+n)%n] == vet[(i+1)%n]);
					else
						f = f and (vet[(i-1+n)%n] != vet[(i+1)%n]);
			
			
				}else{
					if(str[i] == 'o')
						f = f and (vet[(i-1+n)%n] != vet[(i+1)%n]);	
					else
						f = f and (vet[(i-1+n)%n] == vet[(i+1)%n]);
							
					
				}
			}
			if(f){
				for(int i =0;i<n;i++) cout<<mapa[vet[i]];
				return 0;
			
			}
			
		}
	}
	
	cout<<-1;
}