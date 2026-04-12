#include <iostream>
using namespace std;

int main() {
	int H,W;
	bool aw=true;
	cin>>H>>W;
	char m[H][W];
	int wlH[H],wlW[W];
	for(int i=0;i<H;i++){
	    for(int j=0;j<W;j++){
	        cin>>m[i][j];
	        wlW[j]=0;
	    }
	    wlH[i]=0;
	}
	//cin
	for(int k=0;k<H;k++){
	    for(int l=0;l<W;l++){
	        if(m[k][l]=='#'){
	            aw=false;
	        }
	    }
	    if(aw==true){
	        wlH[k]=1;
	    }
	    aw=true;
	}
	//any H to keep
	for(int m1=0;m1<W;m1++){
	    for(int n=0;n<H;n++){
	        if(m[n][m1]=='#'){
	            aw=false;
	        }
	    }
	    if(aw==true){
	        wlW[m1]=1;
	    }
	    aw=true;
	}
	//any W to keep
	for(int p=0;p<H;p++){
	    if(wlH[p]!=1){
	        for(int q=0;q<W;q++){
	            if(wlW[q]!=1){
	                cout<<m[p][q];
	            }
	        }
	        cout<<endl;
	    }
	    
	}
	//cout
	return 0;
}
