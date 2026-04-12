import re
import math

if __name__ == '__main__':

    a, b, c, x, y = [int(n) for n in input().split()]

    ans = 0
    if 2*c <= (a+b):
        if (x > y and a >= c*2) or (x < y and b >= c*2):
            ans = max(x, y)*2*c
        else:
            ans += min(x, y)*2*c
            ans += (x-min(x, y))*a
            ans += (y-min(x, y))*b
        
    else:
        ans = x*a + y*b

    print(ans)
