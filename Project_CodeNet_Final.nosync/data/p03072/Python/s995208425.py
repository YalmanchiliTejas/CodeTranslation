N = int(input())
H = list(map(int,input().split()))
ans = 1
for i in range(N-1):
  if H[i+1] >= H[i]:
    ans += 1
  H[i+1] = max(H[i+1],H[i])
print(ans)