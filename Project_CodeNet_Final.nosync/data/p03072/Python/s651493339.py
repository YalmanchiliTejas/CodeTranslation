N = int(input())
Hs = list(map(int, input().split()))
r = 1
for i in range(1, N):
  if Hs[i] >= max(Hs[0:i]):
    r += 1
print(r)
