a,b,c,x,y=map(int,input().split())
ans=0
min_n=min(x,y)
if a+b>c*2:
    ans+=2*c*min_n
else:
    ans+=(a+b)*min_n

if x>y:
    ans+=min(a*(x-y),2*c*(x-y))
else:
    ans+=min(b*(y-x),2*c*(y-x))

print(ans)

