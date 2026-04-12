a,b,c,x,y = map(int, input().split())
ans = 7000000000
for i in range(100001):
  amount = i*2*c + max(0, x-i)*a + max(0, y-i)*b
  if ans > amount:
    ans = amount
print(ans)


