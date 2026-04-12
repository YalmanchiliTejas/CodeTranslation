a,b,c,x,y = map(int,input().split())
if c > (a+b)/2:
    print(a*x+b*y)
elif x == y:
    print(c*2*x)
else:
    ans = 2*min(x,y)*c
    if x>y:ans+=(x-y)*min(a,2*c)
    else:ans+=(y-x)*min(b,2*c)
    print(ans)