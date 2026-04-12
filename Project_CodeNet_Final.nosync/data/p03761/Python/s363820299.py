from collections import Counter
n = int(input())
a = []
for i in range(n):
    a.append(Counter(input()))
for i in range(97, 97+26):
    m = 100
    for j in range(n):
        m = min(a[j][chr(i)], m)
    print(chr(i)*m, end='')
print()