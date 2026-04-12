#include<bits/stdc++.h>
using namespace std;

int main() {

  int n;
  while( cin >> n, n ) {
    string way;
    int left=4, right=3, front=2, back=5, top=1, under=6;
    int sum = 0, temp;
    for(int i=0; i<n; i++) {
      cin >> way;
      if( way == "North" ) {
	temp = top;
	top = front;
	front = under;
	under = back;
	back = temp;
      }

      else if( way == "East" ) {
	temp = top;
	top = left;
	left = under;
	under = right;
	right = temp;
      }

      else if( way == "West" ) {
	temp = top;
	top = right;
	right = under;
	under = left;
	left = temp;
      }

      else if( way == "South" ) {
	temp = top;
	top = back;
	back = under;
	under = front;
	front = temp;
      }

      else if( way == "Right" ) {
	temp = front;
	front = right;
	right = back;
	back = left;
	left = temp;
      }

      else if( way == "Left" ) {
	temp = front;
	front = left;
	left = back;
	back = right;
	right = temp;
      }

      sum += top;
    }
  
    cout << sum+1 << endl;
  }
}