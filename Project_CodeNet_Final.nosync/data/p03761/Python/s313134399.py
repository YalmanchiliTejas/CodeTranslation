from collections import Counter

n = int(input())
Ans = Counter(input())
for i in range(n-1):
    Ans = Ans & Counter(input())

a = []
for key, value in Ans.items():
    a += [key] * value
a.sort()
print(''.join(a))
