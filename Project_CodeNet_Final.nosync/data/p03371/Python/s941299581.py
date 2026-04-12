a,b,c,x,y = map(int,input().split())
ans = a*x+b*y
for i in range(2*max(x,y)+1):#ABピザを買う枚数で全探索
  ans = min(ans,i*c+max(0,(x-(i//2)))*a+max(0,(y-(i//2)))*b)
print(ans)