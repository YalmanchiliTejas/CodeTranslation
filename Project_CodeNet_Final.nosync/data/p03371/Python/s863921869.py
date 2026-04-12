a,b,c,x,y=map(int,input().split())
money=0
ans=float("INF")

money=a*x+b*y
ans=min(money,ans)
#print(ans)

money=2*min(x,y)*c+(x-min(x,y))*a+(y-min(x,y))*b
ans=min(money,ans)
#print(min(x,y),ans)

money=2*c*max(x,y)
ans=min(money,ans)

print(ans)
