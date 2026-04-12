#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  //     <=          <
  //sort(Jnê, Iè);

  int n;


  while(1){
    cin >> n;

    if(n == 0) break;

    int data[1000];

    int sum = 0;

    for(int i = 0; i < n; i++){

      cin >> data[i];
      sum += data[i];

    }
    sort(data, data+n);

    sum -= data[0];
    sum -= data[n-1];

    sum = sum / (n - 2);

    cout << sum << endl;

  }

  return 0;

}
    


    