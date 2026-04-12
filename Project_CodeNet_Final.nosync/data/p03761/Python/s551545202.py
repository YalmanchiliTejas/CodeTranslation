from collections import Counter

N = int(input())
S = [input() for _ in range(N)]
d = Counter(S[0])
for s in S:
    c = Counter(s)
    for k, v in d.items():
        if c[k] < v:
            d[k] = c[k]
answer = []
for k, v in d.items():
    answer.extend([k] * v)
answer.sort()
print(*answer, sep='')    

