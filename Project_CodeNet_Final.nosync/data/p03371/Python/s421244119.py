import sys
import math
a,b,c,x,y = map(int,input().split())
ans=0
i=0
j=0
while True:
    if i==x and j==y:
        break
    elif i==x:
        if c*2<b:
            ans+=c*2
        else:
            ans+=b
        j+=1
    elif j==y:
        if c*2<a:
                ans+=c*2
        else:
            ans+=a
        i+=1
    else:
        if c*2<(a+b):
            ans+=c*2
        else:
            ans+=a+b
        i+=1
        j+=1
print(ans)