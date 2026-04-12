#include<iostream>                                                                                                                                
#include<stdio.h>                                                                                                                                 
using namespace std;                                                                                                                              
                                                                                                                                                  
int main()                                                                                                                                        
{                                                                                                                                                 
        int n;                                                                                                                                    
        scanf("%d", &n);                                                                                                                          
        int h, h0 = 0, cnt = 0;                                                                                                                   
        for (int i = 1; i <= n; i++)                                                                                                              
        {                                                                                                                                         
                scanf("%d", &h);                                                                                                                  
                if (h >= h0) {                                                                                                                    
                        cnt++;                                                                                                                    
                        h0 = h;                                                                                                                   
                }                                                                                                                                 
        }                                                                                                                                         
        printf("%d", cnt);                                                                                                                        
        return 0;                                                                                                                                 
}