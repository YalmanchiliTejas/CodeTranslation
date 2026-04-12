a,b,c,x,y= map(int, input().split())

if x==y:
    ans=min(c*2*x,(a+b)*x)

else:
    if x>y:
        ans=min(x*c*2,a*x+b*y,y*c*2+(x-y)*a)
    else:
        ans=min(y*c*2,a*x+b*y,x*c*2+(y-x)*b)

print(ans)