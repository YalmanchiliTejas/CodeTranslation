from functools import lru_cache
n,x=map(int,input().split())
h=[1]
for i in range(1,n):
    h.append(2*h[i-1]+3)
@lru_cache(None)
def run(l,x):
    if x==0:
        return 0
    if l==0:
        return 1
    else:
        if x<=h[l-1]+1:
            return run(l-1,x-1)
        elif x==h[l-1]+2:
            return run(l-1,h[l-1])+1
        else:
            return run(l - 1, h[l - 1]) + 1 \
                 + run(l - 1, x - h[l - 1] - 2)
print(run(n,x))
