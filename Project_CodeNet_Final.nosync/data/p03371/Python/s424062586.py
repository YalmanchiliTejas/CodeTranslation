import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    a,b,c,x,y=map(int, input().split())
    if a+b<=2*c:
        ans=x*a+y*b
    else:
        ans=2*c*min(x,y)
        if x>y:
            x-=y
            ans+=min(2*c*x,a*x)
        elif x<y:
            y-=x
            ans+=min(2*c*y,b*y)
    print(ans)
resolve()