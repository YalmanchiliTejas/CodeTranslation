a,b,c,x,y=map(int, input().split())
ans=0
if a+b>2*c:
    ans+=c*min(x, y)*2
    if x==y:
        print(ans)
        exit()
else:
    print(a*x+b*y)
    exit()
if x>y:
    if 2*c<a:
        ans+=2*c*(x-y)
    else:

        ans+=a*(x-y)
else:
    if 2*c<b:
        ans+=2*c*(y-x)
    else:

        ans+=b*(y-x)

print(ans)
