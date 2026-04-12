/**********************************************

1.
2.炭田高輝
3.sumita.takaki@gmail.com

last updated: 2013-07-11@16:33

 **********************************************/
#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cctype>
using namespace std;

int main(void){


        while(1){

                int sum = 1;
                int n=0;
                int a=1, b=2, c=3;
                int tmp = 0;
                        
                cin >> n;
                if(n == 0)break;
                
                vector <string> direction(n);
                
                for(int i=0; i<n; i++){
                        
                        cin >> direction[i];                        

                }
                
                for(int i=0; i<n; i++){

                   
                        if(direction[i] == "North"){
                                
                                tmp = a;
                                a = b;
                                b = 7 - tmp;
                                sum = sum + a;
                        }else if(direction[i] == "East"){

                                tmp = a;
                                a = 7 - c;
                                c = tmp;
                                sum = sum + a;
                        }else if(direction[i] == "West"){

                                tmp = a;
                                a = c;
                                c = 7 -tmp;   
                                sum = sum + a;                             

                        }else if(direction[i] == "South"){

                                tmp = a;
                                a = 7 - b;
                                b = tmp;
                                sum = sum + a;
                        }else if(direction[i] == "Right"){

                                tmp = b;
                                b = c;
                                c = 7 - tmp;                                
                                sum = sum + a;
                        }else if(direction[i] == "Left"){

                                tmp = c;
                                c = b;
                                b = 7 - tmp;                                
                                sum = sum + a;
                        }

                }

                cout << sum << endl;
        }
        
        return 0;


}