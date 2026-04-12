def se(c, x, h, l):
    if h == l:
        return l
    t = (h+l)//2
    if c[t] <= x:
        a = se(c,x,h,t+1)
    else:
        a = se(c,x,t,l)
    return a
        
    
import numpy as np
n = int(input())
a = [int(input()) for i in range(n)]
c = [a[-1]]
diff = np.diff(a)
tmp = np.sum(diff<=0)
if tmp == len(diff):
    print(len(a))
elif tmp == 0:
    print(1)
else:
    for i in a[::-1][1:]:
        if c[-1] <= i:
            c.append(i)
        else:
            c[se(c,i,len(c),0)] = i
    print(len(c))


