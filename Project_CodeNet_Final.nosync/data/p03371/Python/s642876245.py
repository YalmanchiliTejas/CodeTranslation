a,b,c,x,y=[int(i) for i in input().split()]
Min=min(x,y)
ans=0
if c*Min*2<=(a+b)*Min:
    ans+=c*Min*2
else:
    ans+=(a+b)*Min
x,y=x-Min,y-Min
if x>0:
    if c*x*2<=a*x:
        ans+=c*x*2
    else:
        ans+=a*x
if y>0:
    if c*y*2<=b*y:
        ans+=c*y*2
    else:
        ans+=b*y
print(ans)