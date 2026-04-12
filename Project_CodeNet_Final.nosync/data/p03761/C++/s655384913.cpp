#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int n ;
    cin>>n;
    int a[50][26+5] ,m[50+5];
    memset(a,0,sizeof(a));
    for(int i = 0 ; i < 26 ; i++)
    m[i] = 500;
    for(int i = 0 ;  i < n ;i++){
        char s[50+5];
        cin>>s; 
        for(int j = 0 ; j < strlen(s) ; j++){
            a[i][s[j]-'a']++;
        }
    }
   /* for(int i = 0 ; i < n ; i++){
    	for(int j = 0 ; j < 26 ; j++){
    		cout<<a[i][j];
		}
		cout<<endl;
	} */
    for(int i = 0 ; i < n ;i++ ){
        for(int j = 0 ; j < 26 ; j++){
            if(a[i][j]<m[j])
                m[j] = a[i][j];
        }
    }
    int sum = 0;
    for(int i = 0 ; i < 26 ;i++){
        if(m[i]>0){
        	//cout<<m[i];
        	sum++;
		}
            
    }
    //cout<<sum<<endl;
    if(sum==0){
    	cout<<endl;
	}
    else{
        for(int i = 0 ; i < 26 ;i++){
            for(int j = 0 ; j < m[i] ; j++){
                printf("%c",i+'a');
            }
        }
        cout<<endl;
    }
    return 0;
}
