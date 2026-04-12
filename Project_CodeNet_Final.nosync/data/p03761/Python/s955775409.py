from collections import Counter

n = int(input())
S = [input() for i in range(n)]

Min = min(S)
c = Counter(Min)
S.remove(Min)

ans = []
for i, j in c.items():
    flg = 0
    for k in range(j):
        if all((j-k) <= l.count(i) for l in S):
            for m in range(j-k):
                ans.append(i)
            break

ans.sort()
print(''.join(ans))