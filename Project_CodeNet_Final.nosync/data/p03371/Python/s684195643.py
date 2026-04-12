a,b,c,x,y = map(int,input().split())
z = min(x,y)
ans = min((a+b)*z,c*z*2)
if x==y:
    print(ans)
elif x>y:
    ans += min((x-y)*a,(x-y)*c*2)
    print(ans)
else:
    ans += min((y-x)*b,(y-x)*c*2)
    print(ans)