N = int(input())
X = list(map(int,input().split()))

A = sorted(X)
f = N // 2 - 1
b = f + 1
C1 = A[f]
C2 = A[b]

for i in range(N):
  if X[i] <= C1:
    print(C2)
  elif X[i] >= C2:
    print(C1)