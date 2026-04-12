import sys
import numpy as np

readline = sys.stdin.readline

n, x, m = map(int, input().split())
l = np.full(m+1,-1)
l[0] = x
s = set()
s.add(x)
lsum = [-1 for i in range(m+1)]
lsum[0] = x
for i in range(1,m+1):
    a = pow(int(l[i-1]),2,m)
    if a in s:
        if n <= i:
            print(lsum[n-1])
            sys.exit()
        j = np.where(l==a)[0][0]
        if j == 0:
            ans = lsum[i-1]
            n -= i
            ans += (lsum[i-1]) * (n//(i-j))
            if n % (i-j) == 0:
                print(ans)
                sys.exit()
            else:
                d = n % (i-j)
                ans += lsum[d-1]
                print(ans)
                sys.exit()
        else:
            ans = lsum[i-1]
            n -= i
            ans += (lsum[i-1] - lsum[j-1]) * (n//(i-j))
            if n % (i-j) == 0:
                print(ans)
                sys.exit()
            else:
                d = n % (i-j)
                ans += lsum[j+d-1] - lsum[j-1]
                print(ans)
                sys.exit()
    else:
        s.add(a)
        l[i] = a
        lsum[i] = lsum[i-1] + a
