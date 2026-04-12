N = int(input())
H = list(map(int, input().split()))

h = H[0]
cnt = 1
for n in range(1, N):
  if H[n] >= h:
    cnt = cnt + 1
    h = H[n]

print(cnt)