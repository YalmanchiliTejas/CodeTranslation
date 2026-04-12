N = int(input())
H = [int(i) for i in input().split()]
n = 0
h = 0
for i in range(N):
  if H[i] >= h:
    h = H[i]
    n += 1
print(n)
  