from collections import Counter

n = int(input())
ss = [input() for _ in range(n)]

inf = float('inf')
l = [inf] * 26

for s in ss:
    num_of_c = Counter(s)
    for i in range(26):
        l[i] = min(l[i], num_of_c[chr(i+97)])
for i in range(26):
    if l[0] == inf:
        l[0] = 0
    print(chr(i+97) * l[i], end = '')
