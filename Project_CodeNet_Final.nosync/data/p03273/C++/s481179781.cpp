#include <iostream>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	char a[110][110];
	for(int i=0; i<H; ++i) for(int j=0; j<W; ++j) cin >> a[i][j];
	bool f;
	int k;
	for(int i=0; i<H; ++i){
	    f=true;
	    for(int j=0; j<W; ++j) if(a[i][j]=='#'){
	        f=false;
	        break;
	    }
	    if(f){
	        for(k=i; k<H; ++k){
	            for(int j=0; j<W; ++j){
	                if(k+1==H) a[k][j]=' ';
	                else a[k][j]=a[k+1][j];
	            }
	        }
	        --i;
	        --H;
	    }      
	}
	for(int j=0; j<W; ++j){
	    f=true;
	    for(int i=0; i<H; ++i) if(a[i][j]=='#'){
	        f=false;
	        break;
	    }
	    if(f){
	        for(k=j; k<W; ++k){
	            for(int i=0; i<H; ++i){
	                if(k+1==W) a[i][k]=' ';
	                else a[i][k]=a[i][k+1];
	            }
	        }
	        --j;
	        --W;
	    }     
	}
	for(int i=0; i<H; ++i){
	    for(int j=0;j<W; ++j) cout << a[i][j];
	    cout << endl;
	}
	return 0;
}
