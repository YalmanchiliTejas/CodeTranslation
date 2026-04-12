#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <fstream>
#include <sstream>
#include <math.h>
#include <queue>
#include <stack>
#include <math.h>
#include <string.h>


using namespace std;


void f(bool box[12][12]){
    for(int i=1; i<=10; i++){
        for(int j=1; j<=10; j++){
            cout<<box[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int n;
    while(cin>>n){
        for(int roop=0; roop<n; roop++){
            bool box[12][12]={0};
            
            for(int i=1; i<=10; i++){
                for(int j=1; j<=10; j++){
                    cin>>box[i][j];
                }
            }
            //cout<<"----------------------"<<endl;
            
            bool box2[12][12]={0};
            
            for(int i=0; i<(1<<11 - 1); i++){
                memcpy(box2, box, sizeof(box));
                int l[12][12]={0};
                for(int j=1; j<=10; j++){
                    l[0][j]= (i>>(j-1))%2;
                    //cout<<l[0][j];
                }
                
                //cout<<endl;
                
                for(int j=1; j<=10; j++){
                    for(int k=1; k<=10; k++){
                        if(l[j-1][k]==1){
                            box2[j][k]=(box2[j][k]+1)%2;
                            box2[j][k+1]=(box2[j][k+1]+1)%2;
                            box2[j][k-1]=(box2[j][k-1]+1)%2;
                            box2[j-1][k]=(box2[j-1][k]+1)%2;
                            box2[j+1][k]=(box2[j+1][k]+1)%2;
                        }
                    }
                    
                    for(int k=1; k<=10; k++){
                        l[j][k]=box2[j][k];
                    }
                }
                
                bool end_flag=true;
                for(int i=1; i<=10; i++){
                    if(l[10][i]==1){
                        end_flag=false;
                        break;
                    }
                }
                
                
                if(end_flag){
                    for(int i=0; i<=9; i++){
                        for(int j=1; j<=10; j++){
                            cout<<l[i][j];
                            if(j==10)break;
                            cout<<" ";
                        }
                        cout<<endl;
                    }
                    break;
                    
                }
            }
            //cout<<"============================"<<endl;
            
            

        }
                
    }
}