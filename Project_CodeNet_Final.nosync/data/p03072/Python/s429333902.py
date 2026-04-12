N = int(input())
Hs = list(map(int, input().split()))

ans = 1
h = Hs[0]
for i in range(N-1):
  if Hs[i+1] >= h:
    ans += 1
    h = Hs[i+1]
print(ans)
