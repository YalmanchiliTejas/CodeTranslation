#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    int total;
    total=0;
    cin >> n;
    int arr[n];
    for (int i=0; i<n;i++) {
        cin >> arr[i];
    }
    for ( int x=0;x<n;x++){
        bool ishighest = true;
      for (int y=0;y<x;y++){
          if(arr[x]<arr[y]){
              ishighest = false;
              break;
          }
      }
      if (ishighest) total ++;
    }
    cout << total;
}

