#include<iostream>
#include<algorithm>


using namespace std;

int main(void){
    
    int line[12];
    
    for(int i = 0;i < 12;i++){
        
        cin >> line[i];
        
    }
    
    sort(line,line+12);
    
   
    
    for(int i = 0;i < 3;i++){
        
        for(int j = 1;j < 4;j++)
            
            if(line[4 * i ] != line[4 * i + j ]){ cout << "no" << endl; return 0;}
            
        
            
        }
            
            
      cout << "yes" << endl;


return 0;

}
         
    
