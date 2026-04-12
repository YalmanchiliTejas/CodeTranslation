N, X, M = map(int, input().split())

ans, tmp = X, X
s = set()
s.add(X)
for i in range(1, N):
  tmp = (tmp**2) % M
  if tmp == 0:
    break
  if tmp == 1:
    ans += N-i
    break
  if tmp not in s:
    s.add(tmp)
    ans += tmp
  else:
    s = list(s)
    idx = s.index(tmp)
    ans += sum(s[idx:]) * ((N-i)//(len(s)-idx))
    ans += sum(s[idx:idx+(N-i)%(len(s)-idx)])
    break
print(ans)