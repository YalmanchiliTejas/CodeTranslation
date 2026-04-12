from collections import Counter
n = int(input())
s = dict(Counter(input()))
for i in range(n-1):
  c = Counter(input())
  for j,k in s.items():
    s[j] = min(k,c[j])
can_use = []
for i,j in s.items():
  for k in range(j):
    can_use.append(i)
can_use.sort()
print(*can_use,sep='')