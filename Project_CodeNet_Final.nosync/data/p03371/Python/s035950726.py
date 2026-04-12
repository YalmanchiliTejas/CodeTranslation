a,b,c,x,y=map(int,input().split())
if a + b <= 2*c:
    print(a*x + b*y)
elif max(a,b) < 2*c:
    if x > y:
        print(c*y*2 + a*(x-y))
    else:
        print(c*x*2 + b*(y-x))
elif min(a,b) < 2*c:
    if (a < b and x < y) or (a > b and x >y):
        print(c*max(x,y)*2)
    else:
        print(c*min(x,y)*2 + min(a,b)*abs(x-y))
else:
    print(c*max(x,y)*2)