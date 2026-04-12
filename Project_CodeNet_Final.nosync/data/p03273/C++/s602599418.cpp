#include <iostream>
using namespace std;
const int N=100+5;
void delR(char a[N][N],int h,int w,int dr); 
void delC(char a[N][N],int h,int w,int dc);

int main()
{
	int h,w;
	cin>>h>>w;
	char a[N][N];
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			cin>>a[i][j];
	//删行操作 
	int i,j;
	for(i=0;i<h;){
		bool br=true; 
		for(j=0;j<w;j++){
			if(a[i][j]=='#'){
				br=false;	break;
			}
		}
		//删除第i行 
		if(br){
			h--;
			delR(a,h,w,i); 
		}
		else
			i++;
	}
	//删列操作
	for(i=0;i<w;){
		bool bc=true; 
		for(j=0;j<h;j++){
			if(a[j][i]=='#'){
				bc=false;	break;
			}
		}
		//删除第i列 
		if(bc){
			w--;
			delC(a,h,w,i); 
		}
		else
			i++;
	}
	cout<<endl;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++) 
			cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}
void delR(char a[N][N],int h,int w,int dr)
{
	for(int i=dr;i<h;i++)
		for(int j=0;j<w;j++)
			a[i][j]=a[i+1][j];
}

void delC(char a[N][N],int h,int w,int dc)
{
	for(int i=dc;i<w;i++)
		for(int j=0;j<h;j++)
			a[j][i]=a[j][i+1];	
}




