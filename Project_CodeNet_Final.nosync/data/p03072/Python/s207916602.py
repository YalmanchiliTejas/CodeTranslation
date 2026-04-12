N = int(input())
H = list(map(int, input().split()))
A = 0
for i in range(N):
  if H[i] >= max(H[:i + 1]):
    A += 1
print(A)