a,b,c,x,y = map(int,input().split())

ans = a*x+b*y

for i in range(10**5+1):
  tmp = 2*c*i+max(0,x-i)*a+max(0,y-i)*b
  ans = min(ans,tmp)
  
print(ans)