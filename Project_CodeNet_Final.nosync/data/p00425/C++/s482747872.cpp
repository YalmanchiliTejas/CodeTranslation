#include<cstdio>
using namespace std;
char query[6];
class Dice{
  private :
    int up;
    int front;
    int right;
    int left;
    int back;
    int bottom;
    int cnt;
  public :
    Dice(){
      cnt = 1;
      up = 1;
      front = 2;
      right = 3;
      left = 4;
      back = 5;
      bottom = 6;
    }
    int get(){
      return cnt;
    }
    void North(){
      int tmp = up;
      up = front;
      front = bottom;
      bottom = back;
      back = tmp;
      cnt += up;
    }
    void East(){
      int tmp = up;
      up = left;
      left = bottom;
      bottom = right;
      right = tmp;
      cnt += up;
    }
    void West(){
      int tmp = up;
      up = right;
      right = bottom;
      bottom = left;
      left = tmp;
      cnt += up;
    }
    void South(){
      int tmp = up;
      up = back;
      back = bottom;
      bottom = front;
      front = tmp;
      cnt += up;
    }
    void Right(){
      int tmp = front;
      front = right;
      right = back;
      back = left;
      left = tmp;
      cnt += up;
    }
    void Left(){
      int tmp = front;
      front = left;
      left = back;
      back = right;
      right = tmp;
      cnt += up;
    }
};
int main(){
  int n;
  while(true){
    scanf("%d",&n);
    if(n == 0)
      break;
    Dice d;
    for(int i = 0 ; i < n ; i++){
      scanf("%s",query);
      switch(query[0]){
        case 'N' : d.North(); break;
        case 'E' : d.East(); break;
        case 'W' : d.West(); break;
        case 'S' : d.South(); break;
        case 'R' : d.Right(); break;
        case 'L' : d.Left(); break;
      }
    }
    printf("%d\n",d.get());
  }
}

