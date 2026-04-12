import numpy as np

n, x = map(int,input().split())
size = [1]
full_p = [1]
for i in range(n):
    size.append(size[i]*2+3)
    full_p.append(full_p[i]*2+1)

# print(size)
def num_p(x,n):
    if n == 0:
        return 1
    burg = size[n-1]
    if x == 1:
        return 0
    elif x == burg+2:
        return full_p[n-1]+1
    elif x < burg +2:
        return num_p(x-1,n-1)
    elif x > burg+2:
        return full_p[n-1]+1+num_p(x-(burg+2),n-1)

# print(size)
ans = num_p(x,n)

print(ans)
