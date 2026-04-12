a,b,c,x,y=map(int,input().split())

ans=a*x+b*y
for ci in range(max(x,y)+1):
    sumc = 2*ci*c
    sumc += (x-ci)*a if (x-ci)>0 else 0
    sumc += (y-ci)*b if (y-ci)>0 else 0
    ans=min(ans,sumc)

print(ans)