N = int(input())
H = list(map(int, input().split()))

M = 0
cnt = 0

for i in range(N):
  if M <= H[i]:
    M = H[i]
    cnt += 1

print(cnt)