N, X, M = map(int, input().split())
a = [0 for i in range(M+1)]
b = [X]
a[X-1] = 1

for i in range(min(N-1, M)):
  X = X**2%M
  a[X-1] += 1
  b.append(X)
  if a[X-1] > 1:
    break

if len(b) == N:
  print(sum(b))

else:
  ls = b.index(b[-1])
  bloop = b[ls:-1]
  ans = 0
  if ls > 0:
    for i in range(ls):
      ans += b[i]
  loop = (N-ls)//len(bloop)
  ans += sum(bloop) * loop
  if (N-ls)%len(bloop) != 0:
    for i in range((N-ls)%len(bloop)):
      ans += bloop[i]
  print(ans)