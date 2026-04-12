import collections
n = int(input())
s = [input() for i in range(n)]
if n == 1:
  print("".join(sorted(s[0])))
else:
  c = []
  for i in s:
    c.append(collections.Counter(i))
  a = c[0] & c[1]
  for i in range(2, n):
    a &= c[i]
  ans = []
  a = a.most_common()
  for i in a:
    ans.append(i[0]*i[1])
  print("".join(sorted(ans)))