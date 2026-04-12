n = int(input())
H = list(map(int, input().split()))
c = 1
m = H[0]
for i in range(1, n):
  if m <= H[i]:
    c += 1
    m = H[i]
print(c)