  #include <iostream>
  using namespace std;
  //↑デフォルト文
  int main() {
    int r, g, b;

    cin >> r;
    cin >> g;
    cin >> b;

    int answer = (r * 100) + (g * 10) + b;

    if(answer % 4 == 0){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
