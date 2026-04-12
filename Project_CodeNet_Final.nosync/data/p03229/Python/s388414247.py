N = int(input())
A = [int(input()) for i in range(N)]
A.sort()
L, R = A[0], A[N-1]
S = R - L
x, y = 1, N - 2
while x <= y:
  a, b, c, d = abs(L-A[y]), abs(L-A[x]), abs(R-A[y]), abs(R-A[x])
  M = max(a, b, c, d)
  if M == a:
    L = A[y]
    y -= 1
    S += a
  elif M == b:
    L = A[x]
    x += 1
    S += b
  elif M == c:
    R = A[y]
    y -= 1
    S += c
  elif M == d:
    R = A[x]
    x += 1
    S += d
print(S)