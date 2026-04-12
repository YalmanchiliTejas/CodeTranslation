a,b,c,x,y=map(int, input().split())
max_=max(x,y)
cost=100000000000
for i in range(max_+1):
  cost_=i*2*c+a*max(0,x-i)+b*max(0,y-i)
  cost=min(cost_,cost)
print(cost)