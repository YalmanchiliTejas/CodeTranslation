a,b,c,x,y=map(int,input().split())
ans=0
ans+=min(x,y)*min(2*c,a+b)
s=max(0,x-y)
t=max(0,y-x)
ans+=s*min(a,2*c) 
ans+=t*min(b,2*c)
print(ans)
