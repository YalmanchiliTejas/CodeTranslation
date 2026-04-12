from collections import Counter
n = int(input())
l = [{} for _ in range(n)]
for i in range(n):
    l[i] = Counter(input())
for i in range(26):
    w = chr(ord("a") + i)
    c = 51
    for j in range(n):
        c = min(c, l[j][w])
    print(w * c, end = "")
print()
