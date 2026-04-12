N = int(input())
a = list(map(int, input().split()))

x = sum(a)

a.sort(reverse = True)

D = [0] * N

ans = 0
flag = True
while flag:
  k = 0
  for i in range(N):
    k += a[i] // N
  for i in range(N):
    D[i] = a[i] % N + (k - a[i] // N)
  flag = False
  ans += k
  for i in range(N):
    a[i] = D[i]
    if D[i] >= N:
      flag = True

print(ans)

