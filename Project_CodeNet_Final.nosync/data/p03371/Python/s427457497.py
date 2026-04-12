a,b,c,x,y = map(int,input().split())

ans = float('inf')
for i in range(0,max(x,y)*2 + 1,2):
  price = i*c+ max(x-i//2,0)*a + max(y-i//2,0)*b
  ans = min(price,ans)
print(ans)

