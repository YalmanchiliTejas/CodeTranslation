import string
import collections
n = int(input())
res = ''
dic_lst = []
for i in range(n):
  w = collections.Counter(input())
  dic_lst.append(w)
for ch in string.ascii_lowercase:
  cc = 100
  for w in dic_lst:
    cc = min(cc, w[ch])
  res += ch * cc
print(res)
  