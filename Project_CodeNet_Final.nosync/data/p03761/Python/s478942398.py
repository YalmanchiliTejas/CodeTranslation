import collections

n = int(input())
s = [input() for i in range(n)]

c_1 = collections.Counter(s[0])
for i in range(1,len(s)):
  tmp = {}
  c_2 = collections.Counter(s[i])
  for k in c_1:
    tmp[k] = min(c_1[k],c_2[k])
  c_1 = tmp
result = ""
for i in c_1:
  for j in range(c_1[i]):
    result += i
print("".join(sorted(result)))