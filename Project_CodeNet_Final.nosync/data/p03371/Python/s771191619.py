import math
a, b, c, x, y=map(int, input().split())
ans=10**9
for i in range(2*max(x, y)+1):
    if 2*x-i>0:
        aa=math.ceil((2*x-i)/2)*a
    else:
        aa=0
    if 2*y-i>0:
        bb=math.ceil((2*y-i)/2)*b
    else:
        bb=0
    res=aa+bb+i*c
    ans=min(ans, res)
print(ans)