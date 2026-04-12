
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    char a[110][110] = {0};
    int h = 0, w = 0, i = 0, j = 0, num[110][110] = {0}, c = 0, x = 0;
    bool flag;
    cin >> h >> w;
    for(i = 0; i < h; i++)
    {
        for(j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }

    for(i = 0; i < h; i++)
    {
        for(j = 0; j < w; j++)
        {
            if (a[i][j] != '.')
            {
                c = 1;
            }
        }
        if(c == 1)
        {
            c = 0;
            continue;
        }
        for(j = 0; j < w; j++)
        {
             num[i][j] = 1;

        }

    }

      for(i = 0; i < w; i++)
    {

        for(j = 0; j < h; j++)
        {
            if (a[j][i] != '.')
            {
                c = 1;
            }
        }
        if(c == 1)
        {
            c = 0;
            continue;
        }
        for(j = 0; j < h; j++)
        {
             num[j][i] = 1;
        }
    }

  for(i = 0; i < h; i++)
    {
        for(j = 0; j < w; j++)
        {
            if(num[i][j] == 1)
            {
                cout << "";
                x++;
                continue;
            }
        cout << a[i][j];
        }
      if(x == w)
      {
          x = 0;
          continue;
      }
      x = 0;
      cout << endl;
    }


return 0;
}



