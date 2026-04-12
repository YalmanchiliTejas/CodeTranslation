N = int(input())
A = [int(x) for x in input().split()]
A.sort(reverse = True)
D = [0] * N
pos = 1
D[0] = A[0] // N
A[0] = A[0] % N
while D[pos] != D[(pos - 1) % N]:
  pre = (pos - 1) % N
  a = D[pre] - D[pos]
  A[pos] += a
  D[pos] = D[pre] + A[pos] // N
  A[pos] %= N
  pos = (pos + 1) % N
print(D[pos])