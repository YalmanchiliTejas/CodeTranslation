a,b,c,x,y=map(int,input().split())
if a+b<=2*c:
    print(a*x+b*y)
else:
    if x>y:
        ans=2*c*y
        rem=x-y
        ans+=min(2*rem*c,rem*a)
    elif x<y:
        ans=2*c*x
        rem=y-x
        ans+=min(2*rem*c,rem*b)
    else:ans=2*c*x
    print(ans)