#include <iostream>
#include <string>
using namespace std;

class dice{
  int below,side[4];
public:
  int top;
  dice(){top=1; below=6; side[0]=2; side[1]=3; side[2]=5; side[3]=4;};
  void north(),east(),west(),south();
  void right(),left();
};
  
void dice::north()
{
  int x=top;
  top=side[0];
  side[0]=below;
  below=side[2];
  side[2]=x;
}
void dice::east()
{
  int x=top;
  top=side[3];
  side[3]=below;
  below=side[1];
  side[1]=x;
}
void dice::west()
{
  int x=top;
  top=side[1];
  side[1]=below;
  below=side[3];
  side[3]=x;
}
void dice::south()
{
  int x=top;
  top=side[2];
  side[2]=below;
  below=side[0];
  side[0]=x;
}
void dice::right()
{
  int x=side[0];
  side[0]=side[1];
  side[1]=side[2];
  side[2]=side[3];
  side[3]=x;
}
void dice::left()
{
  int x=side[0];
  side[0]=side[3];
  side[3]=side[2];
  side[2]=side[1];
  side[1]=x;
}

int main()
{
  while(true){
    dice sai;
    int n;
    cin >> n;
    if(n<1) break;
    int ans=1;
    for(int i=0;i<n;i++){
      string ward;
      cin >> ward;
      if(ward=="North")	sai.north();
      else if(ward=="East") sai.east();
      else if(ward=="West") sai.west();
      else if(ward=="South") sai.south();
      else if(ward=="Right") sai.right();
      else if(ward=="Left") sai.left();
      ans +=sai.top;  
    }
    cout << ans << endl;
  }
  
  return 0;
}