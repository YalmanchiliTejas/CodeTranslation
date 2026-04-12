#include <iostream>
#include <queue>
#include <string>
using namespace std;

int ruijou(int);

main(){
  int m, n, player[1001], s, i, j, p;

  while(1){
    scanf("%d %d", &m, &n);
    if(m==0 && n==0) break;
    getchar();

    for(i=0;i<=m;i++) player[i]=0;
    
    queue<int> member;
    for(i=1;i<=m;i++) member.push(i);

    for(j=1;j<=n;j++){
      if(member.size()<=1){
	string a;
	getline(cin,a);
      }
      else{
	p=member.front(),member.pop();
	int f=1;
	string temp;
	getline(cin,temp);
	i=temp.size();
	
	if(i==4 && temp=="Fizz"){
	  if(j%3==0 && j%5!=0) f=0;
	}
	else if(i==4 && temp=="Buzz"){
	  if(j%5==0 && j%3!=0) f=0;
	}
	else if(i==8 && temp=="FizzBuzz"){
	  if(j%3==0 && j%5==0) f=0;
	}
	else{
	  int flag=0;
	  for(int count=0;count<i;count++){
	    if(temp[count]<'0' || temp[count]>'9'){
	      flag=1;
	      break;
	    }
	  }
	  if(flag==0){
	    s=0;
	    for(int count=0;count<i;count++){
	      s+=(temp[count]-'0')*ruijou(i-count-1);
	    }
	    if(j%3!=0 && j%5!=0 && j==s){
	      f=0;
	    }
	  }
	}
	if(f==0) member.push(p);
	else player[p]=1;
      }
    }
 
    for(i=1;i<=m;i++){
      if(player[i]==0){
	printf("%d", i);
	break;
      }
    }
    for(j=i+1;j<=m;j++){
      if(player[j]==0){
	printf(" %d", j);
      }
    }
    printf("\n");
  }
  return 0;
}

int ruijou(int a){
  int sum=1;
  for(int i=0;i<a;i++){
    sum*=10;
  }
  return sum;
}