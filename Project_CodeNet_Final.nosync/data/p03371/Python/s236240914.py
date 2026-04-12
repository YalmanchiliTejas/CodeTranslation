import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    import math
    a,b,c,x,y=map(int, input().split())
    cmax=max(x,y)*2
    l=[]
    for i in range(cmax+1):
        amai = max(math.ceil(x - 0.5 * i),0)
        bmai = max(math.ceil(y - 0.5 * i),0)
        l.append(amai*a+bmai*b+i*c)
    print(min(l))
resolve()