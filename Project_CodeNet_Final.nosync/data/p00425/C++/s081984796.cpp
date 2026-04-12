#include<iostream>

using namespace std;
int main()
{

  class dice {

    int ue,shita,migi,hidari,temae,oku,sum;

  public:
    dice(){ue=1;shita=6;migi=3;hidari=4;temae=2;oku=5;sum=1;};
    
    void north(){int tmp;tmp = ue;ue = temae ;temae  = shita;shita = oku   ;oku = tmp  ;sum += ue;};
    void east() {int tmp;tmp = ue;ue = hidari;hidari = shita;shita = migi  ;migi= tmp  ;sum += ue;};
    void west() {int tmp;tmp = ue;ue = migi  ;migi = shita  ;shita = hidari;hidari=tmp ;sum += ue;};
    void south(){int tmp;tmp = ue;ue = oku   ;oku = shita;  ;shita = temae ;temae = tmp;sum += ue;};
    void right(){int tmp;tmp = temae;temae = migi;migi = oku;oku = hidari;hidari = tmp;sum += ue;};
    void left() {int tmp;tmp = temae;temae = hidari;hidari = oku;oku = migi;migi = tmp;sum += ue;};
    void print(){cout << ue << shita << migi << hidari << temae << oku << "sum=" <<sum <<endl;};
    void ans(){cout << sum << endl;};
  }; 


  while(1){
    dice d;
    int n;
    cin >>n;
    if(n==0) break;

    for(int i = 0;i < n;i++){
      string str;
      cin >> str;

      if(str == "North") d.north();
      else if(str == "East") d.east();
      else if(str == "South") d.south();
      else if(str == "West") d.west();
      else if(str == "Right") d.right();
      else if(str == "Left") d.left();
    }

    d.ans();
  }

  return 0;

}
