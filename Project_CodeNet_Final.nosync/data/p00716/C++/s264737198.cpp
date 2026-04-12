#include <iostream>
using namespace std;

main() {
  int m;
  cin >> m;
  for(int t = 0; t < m; t++) {
    int fund;
    int year;
    int n;
    cin >> fund;
    cin >> year;
    cin >> n;

    int maxi;
    for(int i = 0; i < n; i++) {
      int isFukuri, yTesu;
      double yRiritsu;
      cin >> isFukuri >> yRiritsu >> yTesu;
      int tmp = fund;
      int rishiSum = 0;
      for(int j = 0; j < year; j++) {
	int rishi = int(tmp * yRiritsu);
	rishiSum += rishi;
	if(isFukuri) tmp = tmp + rishi - yTesu;
	else         tmp = tmp - yTesu;
      }
      if(!isFukuri) tmp += rishiSum;
      if(i == 0 || tmp > maxi) maxi = tmp;
    }
    cout << maxi << endl;
  }
}