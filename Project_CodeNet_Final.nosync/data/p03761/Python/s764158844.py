
from collections import defaultdict
n = int(input())
s = [list(input()) for _ in range(n)]
s_dict = {}


set_s = set(s[0])
for li in s[1:]:
  set_s = set_s & set(li)


for i in set_s:
  s_dict[i] = 0

for i in s[0]:
  if i in s_dict:
    s_dict[i] += 1

for sub in s[1:]:
  tmp_dict = defaultdict(int)
  for char in sub:
    if char in s_dict:
      tmp_dict[char] += 1
  for k, v in tmp_dict.items():
    if tmp_dict[k] < s_dict[k]:
      s_dict[k] = v

li = []
for k, v in s_dict.items():
  li.append(k*v)

li = sorted(li)
output = ""

for i in li:
  output += i 
print(output)


