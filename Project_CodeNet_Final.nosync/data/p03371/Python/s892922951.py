import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    import math
    a,b,c,x,y=map(int, input().split())
    # ABピザを奇数枚買っても1枚無駄になるから、ABピザは2枚を1枚だと考える
    # cの値段を2倍にして枚数を半分に
    cmax=max(x,y) # ABピザの最大枚数(2枚を1枚と考えたとき)
    c=2*c
    l=[]
    for i in range(cmax+1):
        amai = max(x - i,0)
        bmai = max(y - i,0)
        l.append(amai*a+bmai*b+i*c)
    print(min(l))
resolve()