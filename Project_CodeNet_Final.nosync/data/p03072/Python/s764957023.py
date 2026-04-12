N = int(input())
H = [int(x) for x in input().split()]
A = list(H)
for i in range(N):
  for j in range(i):
    if H[i] < H[j]:
      A[i] = 0
      break
print(len([i for i in A if i != 0]))