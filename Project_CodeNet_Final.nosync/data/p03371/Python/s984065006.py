import sys
input=sys.stdin.readline

a,b,c,x,y=map(int,input().split())
minxy=min(x,y)
deff=max(x,y)-minxy
if a+b<=2*c:
    print(a*x+b*y)
else:
    half=2*c*minxy
    if max(x,y)==x and a<=2*c:
        print(half+deff*a)
    elif max(x,y)==y and b<=2*c:
        print(half+deff*b)
    else:
        print(half+deff*2*c)