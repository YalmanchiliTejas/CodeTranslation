ni = lambda: int(input())
nm = lambda: map(int, input().split())
nl = lambda: list(map(int, input().split()))

a,b,c,x,y = nm()

min_cost = 10**10
for i in range(10**5+1):
  cost=2*i*c+max(0,x-i)*a+max(0,y-i)*b
  min_cost = min(min_cost,cost)
print(min_cost)
