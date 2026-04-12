n = int(input())
s = [list(input()) for _ in range(n)]
a = set(s[0])
for i in s:
  a = a & set(i)
al = list(a)
for j in a:
  countl = []
  for k in s:
    countl.append(k.count(j))
  for _ in range(min(countl) - 1):
    al.append(j)
print("".join(sorted(al)))
