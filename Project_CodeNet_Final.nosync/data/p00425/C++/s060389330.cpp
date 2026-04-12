#include<iostream>
#include<algorithm>
class dice{
  char face[6];
public:
  dice(){for(char i=0;i<6;++i)face[i]=i+1;}
  char top(){return face[0];}
#define decl(a,b,c,d,e,f) char temp[6]={face[a-1],face[b-1],face[c-1],face[d-1],face[e-1],face[f-1]}
#define impl(x,a,b,c,d,e,f) void x(){decl(a,b,c,d,e,f);std::copy(temp,temp+6,face);}
  impl(North,2,6,3,4,1,5)
  impl(East,4,2,1,6,5,3)
  impl(West,3,2,6,1,5,4)
  impl(South,5,1,3,4,6,2)
  impl(Right,1,3,5,2,4,6)
  impl(Left,1,4,2,5,3,6)
};
int main(){
  int n;
  while(1){
    std::cin>>n;
	if(!n)return 0;
	dice d;
	int sum=1;
#define op(x) if(str==#x){d.x();sum+=d.top();continue;}
	while(n--){std::string str;std::cin>>str;op(North)op(East)op(West)op(South)op(Right)op(Left)}
	std::cout<<sum<<std::endl;
  }
}