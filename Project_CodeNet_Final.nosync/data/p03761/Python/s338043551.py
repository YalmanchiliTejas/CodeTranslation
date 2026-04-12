import collections

n = int(input())

sets = None
s_lst = []
dic = {}
for i in range(n):
  s = input()
  s_lst.append(s)
  if i == 0:
    sets = set(s)
  else:
    sets &= set(s)

for s in s_lst:
  c = collections.Counter(s)
  for k in sets:
    if not k in dic:
      dic[k] = c[k]
    else:
      dic[k] = min(dic[k], c[k])

res = ''
for key in sorted(list(sets)):
  res += key * dic[key]
print(res)