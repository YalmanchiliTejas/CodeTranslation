import numpy as np
a,b,c,x,y = map(int,input().split())
ans = min(a+b,c*2)*min(x,y)
if x > y:
    ans += min(a,c*2) * (x-y)
elif x < y:
    ans += min(b,c*2) * (y-x)
print(ans)