from collections import Counter
n = int(input())
S = [Counter(input()) for _ in range(n)]

t = S[0]
for i in range(1,n):
    t = t & S[i]

print(''.join(sorted(list(t.elements()))))
