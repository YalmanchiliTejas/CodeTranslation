from collections import Counter
n = int(input())
S = [input() for i in range(n)]
common = set(S[0])
cnt = Counter(S[0])
for i in range(0,n):
    c = Counter(S[i])
    common = common & set(c.keys())
    for j in cnt.keys():
        if j in common and cnt[j] > c[j]:
            cnt[j] = c[j]
        elif j not in common:
            cnt[j] = 0

ans = []          
for k,v in cnt.items():
    ans.append(k*v)

ans.sort()
print(''.join(ans))