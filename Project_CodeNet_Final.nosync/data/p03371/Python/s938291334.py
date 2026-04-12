a,b,c,x,y=map(int,input().split())
ans=min(x,y)*2*c
if x>y:
    ans+=(x-y)*a
else:
    ans+=(y-x)*b
anss=min(max(x,y)*2*c,a*x+b*y)
print(min(anss,ans))