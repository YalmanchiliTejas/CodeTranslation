N = int(input())
H = list(map(int,input().split()))
ans = 1

for i in range (1,N):
  if max(H[0:i]) <= H[i]:
    ans = ans + 1
print(ans)