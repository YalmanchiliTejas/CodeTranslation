a,b,c,x,y = map(int,input().split())

ans = float('inf')
for i in range(0,2*10**5+1):
  cost = c * i
  cost += a * max(0, x - i//2)
  cost += b * max(0, y - i//2)
  ans = min(ans,cost)  
print(ans)  