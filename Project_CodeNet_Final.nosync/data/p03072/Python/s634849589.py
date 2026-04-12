n = int(input())
h = list(map(int, input().split()))

flag = True
ans = 1
for i in range(n-1, 0, -1):
  a = h[0:i]
  if h[i] >= max(a):
    ans+=1
print(ans)