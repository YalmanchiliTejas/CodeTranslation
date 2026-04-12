N = int(input())
a = list(map(int,input().split()))
x = [0]
ans = 0
for i in range(N):
  y = a[i]
  if max(x) <= y:
    ans += 1
  x.append(y)
print(ans)