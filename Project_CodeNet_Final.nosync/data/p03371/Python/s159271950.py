a,b,c,x,y=map(int,input().split())
ans=0
if a+b<=c*2:
    print(a*x+b*y)
    exit()
elif x>=y:
    ans+=c*y*2
    x-=y
    if a>=c*2:
        ans+=c*2*x
    else:
        ans+=a*x
elif y>x:
    ans+=c*x*2
    y-=x
    if b>=c*2:
        ans+=c*2*y
    else:
        ans+=b*y
print(ans)
