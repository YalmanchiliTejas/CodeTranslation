import re
N = int(input())
s = input()
index = int(input())-1

ss = s[index]
ans = s
for ii, i in enumerate(s):
  if i != ss:
    ans = ans.replace(i, '*')
print(ans)