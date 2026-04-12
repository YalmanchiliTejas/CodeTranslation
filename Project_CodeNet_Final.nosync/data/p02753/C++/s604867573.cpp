					#include<bits/stdc++.h>

					using namespace std;
					int main()
					{
                      string c;
                      cin >> c;
                      int a = 0, b = 0;
                      a += c[0] == 'A';
                      b += c[0] == 'B';
                      a += c[1] == 'A';
                      b += c[1] == 'B';
                      a += c[2] == 'A';
                      b += c[2] == 'B';
                      if(a && b)
                        cout << "Yes";
                      else cout << "No";	 
                    }