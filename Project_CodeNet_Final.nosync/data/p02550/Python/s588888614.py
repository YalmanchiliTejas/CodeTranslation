N, X, M = map(int, input().split())
checklist = [True] * 100000
ind = 0
l = [X]
while True:
  t = l[-1] ** 2 % M
  if checklist[t]:
    l.append(t)
    checklist[t] = False
  else:
    ind = l.index(t)
    break
S = sum(l[ind:])
L = len(l)
ans = 0
if N <= L:
  ans = sum(l[:N])
else:
  ans = sum(l)
  N -= L
  ans += S * (N // (L - ind))
  ans += sum(l[ind:ind+(N % (L - ind))])
print(ans)