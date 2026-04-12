from collections import Counter as cnt

n = int(input())
c = cnt(input())

for _ in range(n-1):
    s = cnt(input())
    for key in c.keys():
        c[key] = min(c[key], s[key]) 
else:
    print("".join(sorted([key * c[key] for key in c.keys()])))