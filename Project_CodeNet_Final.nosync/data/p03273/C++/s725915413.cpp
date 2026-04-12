#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std;
char a[110][110];
int row,col;
int delrow[110],delcol[110];

void deleteOneCol(int k){
int j,i;
  for(j=k+1;j<col;j++)
    for(i=0;i<row;i++)
      a[i][j-1]=a[i][j];
  col--;
}

void deleteOneRow(int k){
int i,j;
  for(i=k+1;i<row;i++)
    for (j=0;j<col;j++)
      a[i-1][j]=a[i][j];
  row--;  
}

void delRow(){
  for (int i=row;i>=0;i--)
    if (delrow[i]==1)
	  deleteOneRow(i);	
}

void delCol(){
	for (int j=col;j>=0;j--)
	  if (delcol[j]==1)
	    deleteOneCol(j);
}

void drow(){
  int i,j;
  char c='.';
  for(i=0;i<row;i++){
    for (j=0;j<col;j++)
	  if (a[i][j]!=c)
	    break;
	if (j>=col)
	  delrow[i]=1; 
	
  }
	
}

void dcol(){
  int i,j;
  char c='.';
  for(j=0;j<col;j++){
    for (i=0;i<row;i++)
	  if (a[i][j]!=c)
	    break;
	if (i>=row){
	  delcol[j]=1;	
	}
  }	
	
}

int main() {
	int i,j;

	
	//freopen("input01.txt","r",stdin);
	
	cin>>row>>col;

	for (i=0;i<row;i++)
	  for(j=0;j<col;j++)
	    cin>>a[i][j];
	
	drow();//检查并标记 
	dcol();//
	delRow();
	delCol();
	  
	for (i=0;i<row;i++){
	  for(j=0;j<col;j++)
		  cout<<a[i][j];
      cout<<endl;
 	}
	
	return 0;
}