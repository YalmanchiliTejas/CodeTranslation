a,b,c,x,y = map(int, input().split())
if (a+b <= c*2):
    print(a*x+b*y)
else:
    if (x>=y):
        print(min(y*c*2+(x-y)*a,x*c*2))
    else:
        print(min(x*c*2+(y-x)*b,y*c*2))