import collections
import string
n = int(input())
res = []
for _ in range(n):
  s = list(input())
  cnt = collections.Counter(s)
  res.append(cnt)

ans = ""
for cha in list(string.ascii_lowercase):
  hoge = []
  for cnt in res:
    if(cha in cnt):
      hoge.append(cnt[cha])
  if (len(hoge) == n) :
    ans += cha * min(hoge)
print(ans)      
