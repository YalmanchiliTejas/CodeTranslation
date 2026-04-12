a,b,c,x,y=map(int,input().split())
if c-(a+b)*(1/2)>=0:
    print(a*x+b*y)
else:
    z=min(x,y)*2
    ans1=int(a*x+b*y+(c-(a+b)*(1/2))*z)
    z=max(x,y)*2
    if x-z/2<0:
        x=0
    else:
        x=int(x-z/2)
    if y-z/2<0:
        y=0
    else:
        y=int(y-z/2)
    ans2=a*x+b*y+c*z
    print(min(ans1,ans2))

