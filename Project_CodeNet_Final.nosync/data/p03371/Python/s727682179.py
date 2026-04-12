#ABC095-C
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(input())
def S(): return list(input())
a,b,c,x,y=IL()
c=c*2
if c<=a:
    if c<=b:
        print(c*max(x,y))
    else:
        print(c*x+max(0,(y-x)*b))
elif c<=b:
    print(c*y+max(0,(x-y)*a))
elif c<=a+b:
    if x>=y:
        print(c*y+a*(x-y))
    else:
        print(c*x+b*(y-x))
else:
    print(a*x+b*y)