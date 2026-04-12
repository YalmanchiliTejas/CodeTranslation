N = int(input().rstrip())
H = tuple(map(int, input().split()))

w = H[0]
c = 1
for i in range(1, N):
  if w <= H[i]:
    c += 1
    w = H[i]

print(c)
