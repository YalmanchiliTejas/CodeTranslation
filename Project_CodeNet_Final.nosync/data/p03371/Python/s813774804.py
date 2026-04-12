A,B,C,X,Y = map(int,input().split())
ans = 100000000000000000000000000000000000000
for c in range (0,100001):
  price = A*max(0,X-c)+B*max(0,Y-c)+C*2*c
  if price < ans:
    ans = price
print(int(ans))
