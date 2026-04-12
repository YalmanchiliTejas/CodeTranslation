#include <iostream>
using namespace std;
int h,w,cnt,Cnt,p,P;
int main() {
	cnt=0;
	Cnt=0;
  p=0;P=0;
	cin>>h>>w;
	char a[h][w];
	int b[h]={0};
	int c[w]={0};
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w-1;j++){
			if(a[i][j]!=a[i][j+1]||a[i][j]=='#'){
				break;
			}else if(j==w-2){
				b[i]=1;
				cnt++;
			}
		}
	}
	for(int j=0;j<w;j++){
		for(int i=0;i<h-1;i++){
			if(a[i][j]!=a[i+1][j]||a[i][j]=='#'){
				break;
			}else if(i==h-2){
				c[j]=1;
				Cnt++;
			}
		}
	}
	for(int i=0;i<h;i++){
		if(b[i]==0){
          p++;
		for(int j=0;j<w;j++){
			if(c[j]==0){
              P++;
				cout<<a[i][j];
				if(Cnt!=w-P){}//cout<<" ";
              else if(cnt!=h-p)cout<<endl;
			}
		}
		P=0;
		}
	}
	return 0;
}