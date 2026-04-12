N = int(input())
X = list(map(int, input().split()))
L = []
for i in range(N):
  L.append([X[i], i])
L.sort()
for i in range(N):
  if i < N // 2:
    L[i].append(L[N // 2][0])
  else:
    L[i].append(L[N // 2 - 1][0])
for i in range(N):
  L[i][0], L[i][1] = L[i][1], L[i][0]
L.sort()
for i in range(N):
  print(L[i][2])