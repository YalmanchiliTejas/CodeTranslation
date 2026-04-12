a,b,c,x,y=map(int,input().split())
cnt_max=max(x,y)
ans=2*c*cnt_max
if a+b<=2*c:
    print(a*x+b*y)
else:
    if x<y:
        cnt=y-x
        print(min(2*c*x+cnt*b,ans))
    elif y<x:
        cnt=x-y
        print(min(2*c*y+cnt*a,ans))
    else:
        print(min(2*c*(x+y),ans))
    