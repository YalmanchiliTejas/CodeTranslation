n = int(input())
raw = []
for _ in range(n):
  now = input()
  add = []
  for j in range(len(now)):
    add.append(now[j])
  raw.append(add)
abc = 'qwertyuiopasdfghjklzxcvbnm'
ABC = []
for j in range(26):
  ABC.append(abc[j])
ABC.sort()
ans = ''
for j in range(26):
  use = ABC[j]
  here = []
  for i in range(n):
    here.append(raw[i].count(use))
  ans += use * min(here)
print(ans)