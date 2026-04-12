N = int(input())
H = list(map(int, input().split()))
n = 0
ans = 1

for i in range(N-1):
  if H[i+1] >= H[n]:
    ans += 1
    n = i+1

print(ans)