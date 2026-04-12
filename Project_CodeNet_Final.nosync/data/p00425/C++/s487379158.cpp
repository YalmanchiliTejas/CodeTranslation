#include <iostream>
using namespace std;

struct state{
  int top, front, right;
  int tmp;

  state(){};
  state(int t, int f, int r){ top=t, front=f, right=r; }

  void north(){    tmp = top;
    top = front;
    front = 7 - tmp;
  }
  void east(){ tmp = top;
    top = 7 - right;
    right = tmp;
  }
  void west(){ tmp = top;
    top= right;
    right = 7- tmp;
  }
  void south(){ tmp=top;
    top=7-front;
    front = tmp;
  }
  void Right(){ tmp=front;
    front = right;
    right = 7-tmp;
  }
  void Left(){ tmp = front;
    front = 7-right;
    right = tmp;
  }
};

int main(){
  int n;
  state s;
  string str;

  while( cin >> n && n){
    s = state(1,2,3);

    int sum = 1;
    while( n-- ){
      cin >> str;
      if( str == "North" )	s.north();
      else if( str == "East")   s.east();
      else if( str == "West")   s.west();
      else if( str == "South")  s.south();
      else if( str == "Right")  s.Right();
      else                      s.Left();

      sum += s.top;
    }
    cout << sum << endl;

  }
}