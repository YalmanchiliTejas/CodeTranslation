import numpy as np
import sys

input = sys.stdin.readline

A,B,C,X,Y = map(int,input().split())


ans = A*X+B*Y
acnt = X
bcnt = Y

for i in range(max(X,Y)):
    tmp = ans

    if acnt > 0:
        acnt-=1
        tmp -= A
    if bcnt > 0:
        bcnt-=1
        tmp -= B

    ans =min(ans, tmp + C*2)

print(ans)


