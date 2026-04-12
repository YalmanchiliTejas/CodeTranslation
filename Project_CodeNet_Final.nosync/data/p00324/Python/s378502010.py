from collections import defaultdict

dic = defaultdict(list)
keys = set()
n = int(input())
acc = 0
dic[0].append(0)
keys.add(0)
for i in range(1, n + 1):
  d = int(input())
  acc += d
  dic[acc].append(i)
  keys.add(acc)

ans = 0
for key in keys:
  lst = dic[key]
  ans = max(ans, max(lst) - min(lst))

print(ans)
