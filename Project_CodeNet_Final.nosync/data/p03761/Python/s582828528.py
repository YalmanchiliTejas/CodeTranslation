from collections import Counter

n = int(input())
A = list(input())

for i in range(n-1):
    B = list(input())
    A = list((Counter(A) & Counter(B)).elements())

A.sort()

ans = "".join(A)

print(ans)