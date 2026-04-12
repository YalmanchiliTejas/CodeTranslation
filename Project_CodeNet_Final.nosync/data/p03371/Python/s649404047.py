a,b,c,x,y=map(int,input().split())

if a+b<=2*c:
    ans=a*x+b*y
else:
    if x>=y:
        ans=y*2*c
        ans+=(x-y)*a
    else:
        ans=x*2*c
        ans+=(y-x)*b

com=max(x, y) * (2 * c)
print(min(com,ans))
