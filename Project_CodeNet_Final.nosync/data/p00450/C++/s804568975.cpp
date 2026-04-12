#include<iostream>
#include<stack>
using namespace std;
#define WHITE 0
#define BLACK 1
int main()
{
  int n,i,color,num;
  stack<int>table;
  while(cin>>n,n){
    while(table.size())table.pop();
    for(i=1;i<=n;i++){
      cin>>color;
      if(table.empty()){
	table.push(color==WHITE?1:-1);
      }else if(i&1){
	num=table.top();
	if(num>0&&color==WHITE){num++;table.pop();}
	else if(num<0&&color==BLACK){num--;table.pop();}
	else num=(color==WHITE?1:-1);
	table.push(num);
      }else{
	num=table.top();
	table.pop();
	if(num>0&&color==WHITE)num++;
	else if(num<0&&color==BLACK)num--;
	else{
	  if(table.empty()){
	    num=-num+(color==WHITE?1:-1);
	  }else{
	    num=-num+(color==WHITE?1:-1)+table.top();
	    table.pop();
	  }
	}
	table.push(num);
      }
    }
    num=0;
    while(table.size()){
      if(table.top()>0)num+=table.top();
      table.pop();
    }
    cout<<num<<endl;
  }
}