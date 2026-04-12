INF = 10**10
N = int(input())
S = [list(input()) for _ in range(N)]
seti = set()
for i in S:
  if not seti:
    seti = set(i)
  else:
    seti &= set(i)
ans = {}
for i in seti:
  ans.setdefault(i, INF)
  for j in S:
    ans[i] = min(ans[i], j.count(i))

ans_sorted = sorted(ans.items(), key=lambda x:x[0])

ret = ""
for k, v in ans_sorted:
  ret += k * v
print(ret)