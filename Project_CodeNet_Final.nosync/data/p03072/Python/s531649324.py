N = int(input())
H = list(map(int, input().split()))

M = H[0]
i = 0

for h in H:
  if h >= M:
    M = h
    i += 1

print(i)