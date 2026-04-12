import collections
n = int(input())
s = [list(input()) for i in range(n)]

cnts = [collections.Counter(si) for si in s]
inter = set(s[0])
for i in range(1, n):
  inter = inter & set(s[i])
  
ans = {k:v for k, v in cnts[0].items() if k in list(inter)}
for i in range(1, n):
  for j in inter:
    if j in cnts[i].keys():
      ans[j] = min(cnts[i][j], ans[j])

moji = ""
ans = sorted(ans.items(), key=lambda x:x[0])
for k, v in ans:
  moji += "".join([k] * v)
print(moji)