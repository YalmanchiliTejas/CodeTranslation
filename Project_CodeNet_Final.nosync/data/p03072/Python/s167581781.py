N = int(input())
H = list(map(lambda h: int(h), input().split(" ")))
M = 0
cnt = 0

for i in range(N):
  if M <= H[i]:
    cnt += 1
    M = H[i]

print(cnt)