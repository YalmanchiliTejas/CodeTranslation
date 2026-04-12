n = int(input())
h = list(map(int,input().split()))
m = 0
ans = 0
for i in h:
  ans += (i>=m)
  m = max(m,i)
print(ans)