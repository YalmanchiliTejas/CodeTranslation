N = int(input())
H = list(map(int, input().split()))
ans = 0
for i in range(N):
  if H[i] >= max(H[0:i+1]):
    ans += 1 
print(ans)