import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    a,b,c, x,y = f()
    ans = 0
    if 2*c <= a+b:
        ans += 2*c*min(x,y)
    else:
        ans += (a+b)*min(x,y)
    
    mxy = min(x,y)
    x -= mxy
    y -= mxy

    if x:
        if 2*c <= a:
            ans += x * 2*c
        else:
            ans += x * a
    if y:
        if 2*c <= b:
            ans += y* 2*c
        else:
            ans += y*b
    
    print(ans)


solve()
