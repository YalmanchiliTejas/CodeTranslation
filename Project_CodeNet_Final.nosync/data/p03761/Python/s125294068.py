from collections import defaultdict
n = int(input())
dic = defaultdict(int)
rec = "abcdefghijklmnopqrstuvwxyz"
for i in range(n):
    tmp = defaultdict(int)
    s = input()
    for j in range(len(s)):
        tmp[s[j]] += 1
    for k in range(len(rec)):
        if i == 0:
            dic[rec[k]] = tmp[rec[k]]
        else:
            dic[rec[k]] = min(dic[rec[k]], tmp[rec[k]])

t = ""
for k, v in dic.items():
    t += k * v

print("".join(sorted(list(t))))