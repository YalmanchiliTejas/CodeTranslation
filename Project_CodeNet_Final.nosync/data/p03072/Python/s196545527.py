N = int(input())
H = list(map(int, input().split()))
ans = 0
max = H[0]
for i in range(N-1):
  if H[i+1] >= max:
    ans += 1
    max = H[i+1]
print(ans+1)