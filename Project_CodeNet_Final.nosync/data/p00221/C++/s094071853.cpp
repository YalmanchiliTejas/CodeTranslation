#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string> 
#include <sstream>  
#include <vector> 
using namespace std;
  
int main(){

    int m,n;
    while(cin >> m >> n){
        if(m == 0 and n == 0){break;}
        int player[m + 1],speaker = 1,nokori = m;
        string kotaetayatu,kotaerubekimono;
        for(int i = 1;m >= i;i++){player[i] = 1;}
            for(int number = 1;n >= number;number++){
                for(int NxstSpeaker = speaker;true;NxstSpeaker++){
                    if(NxstSpeaker > m){NxstSpeaker = 1;}
                    
                    if(player[NxstSpeaker] == 1){
                        stringstream ss;ss << number;
                        kotaerubekimono  = ss.str(); 
                        if(number % 3 == 0){kotaerubekimono = "Fizz";}
                        if(number % 5 == 0){kotaerubekimono = "Buzz";}
                        if(number % 3 == 0 and number % 5 == 0){kotaerubekimono = "FizzBuzz";}
                        cin >> kotaetayatu;
                        if(nokori > 1){
                            if(kotaetayatu != kotaerubekimono){player[NxstSpeaker] = 0;nokori--;}
                            speaker = NxstSpeaker + 1;
                        }
                        break;
                    }
                }
            }
        int hatena = 1;
        for(int ii = 1;m >= ii;ii++){if(player[ii] == 1){if(hatena == 1){cout << ii;hatena = 0;}else{cout << " " << ii;}}}
        cout << endl;
    } 
}