a,b,c,x,y=list(map(int,input().split()))
res=[]
for i in range(max(x,y)+1):
  money=c*i*2
  money += (max(0,x-i)*a + max(0,y-i)*b)
  res.append(money)
print(min(res))