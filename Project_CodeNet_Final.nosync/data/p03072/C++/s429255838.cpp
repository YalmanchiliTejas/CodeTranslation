    #include <stdio.h>
    #include <iostream>
    using namespace std;
    int main()
    {
      int s, n, i, h, maxheight;
      s = 0;
      maxheight = 0;
      cin >> n;
      for(i =0; i<n; i++)
      {
        cin >> h;
        if(h >= maxheight)
        {
          s++;
          maxheight = h;
        }
      }
      cout << s << endl;
      return 0;
    }