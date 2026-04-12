from collections import Counter

n = int(input())
c = Counter(input())

for i in range(n-1):
    c&=Counter(input())

print("".join(sorted(c.elements())))