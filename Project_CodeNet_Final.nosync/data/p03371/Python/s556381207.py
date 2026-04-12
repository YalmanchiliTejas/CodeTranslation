import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    import math
    a,b,c,x,y=map(int, input().split())
    cmax=max(x,y)*2
    l=[]
    for i in range(cmax+1):
        amai = math.ceil(x - 0.5 * i)
        bmai = math.ceil(y - 0.5 * i)
        if 0.5*i>=x and 0.5*i>=y:
            amai=0
            bmai=0
        elif 0.5*i>=x:
            amai=0
        elif 0.5*i>=y:
            bmai=0
        l.append(amai*a+bmai*b+i*c)
    print(min(l))
resolve()