from collections import Counter

n = int(input())
res_c = Counter(input())
for i in range(n-1):
    cur_c = Counter(input())
    new_c = {}
    for key,val in res_c.items():
        # print(key,val)
        new_c[key] = min(val,cur_c[key])
        res_c = new_c
# print(res_c)
s = []
for key,val in res_c.items():
    s.append(key*val)
s.sort()
print("".join(s))
