        #include <bits/stdc++.h>
        using namespace std;
		typedef long long int ll; 

        int main() {
          ll N;
          cin>> N ; 
		  ll s[N], t[N];
          
          for(ll i=0; i<N; i++){
            cin >> s[i];
          }

         for(ll i=0; i<N; i++){
            t[i] = s[i] + s[N-1-i];
         }
         
         ll answer = -80000000000;  
         // C=A-B 
         for(ll C=1; C<N; C++){
           ll S=0;
           ll temp =0; 
           for(ll j=1; j < (N-1)/C; j++ ){
             temp += C;
             S+= t[temp]; 
             ll A = N-1 -temp; 
             if(A>C){
               if(A%C!=0) answer = max( S, answer ); 
               if(A%C==0 && A>(N-1)/2) answer = max( S, answer ); 
             }
           }
         }  
         if (answer <0 ) answer =0;   
         cout << answer;  
        }