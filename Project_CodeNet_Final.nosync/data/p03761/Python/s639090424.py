from collections import Counter

n = int(input())
mn = [100 for x in range(26)]
exist = [True for x in range(26)]
for _ in range(n):
    l = list(input())
    d = Counter(l)
    for i in range(26):
        if d[chr(i+97)] == 0:
            exist[i] = False

    for key, val in d.items():
        mn[ord(key)-97] = min(mn[ord(key)-97], val)
for i in range(26):
    if exist[i]:
        print(chr(i+97)*mn[i], end='')
