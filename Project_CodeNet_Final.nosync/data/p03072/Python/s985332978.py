N = int(input())
H = list(map(int, input().split()))

index = 0
ans = 1

for i in range(1, N):
  if H[index] <= H[i]:
    ans += 1
    index = i

print(ans)
