a,b,c,x,y=map(int,input().split())
chk=min(x,y)
ans=max(x,y)*c*2
ans=min(ans,a*x+b*y,chk*c*2+a*(x-chk)+b*(y-chk))
print(ans)