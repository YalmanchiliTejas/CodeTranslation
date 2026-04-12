import collections
import string

n = int(input())
S = [set() for _ in range(n)]
S_list = []

for i in range(n):
    s = str(input())
    S_list.append(s)
    for w in s:
        S[i].add(w)

new_set = S[0]
for i in range(1,n):
    new_set = new_set & S[i]

Count_dict = {}
for w in new_set:
    new = {w:2500}
    Count_dict.update(new)

for i in range(n):
    for key in Count_dict.keys():
        num = S_list[i].count(key)
        # print(key)
        # print(num)
        if num <= Count_dict[key]:
            Count_dict[key] = num

Count_dict = sorted(Count_dict.items())

ans = ''
for i in range(len(Count_dict)):
    ans += Count_dict[i][0] * Count_dict[i][1]

print(ans)
