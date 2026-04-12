from collections import Counter
N = int(input())

cnt = Counter()
for i in range(26):
    s = chr(ord("a")+i)
    cnt[s] = 100
for _ in range(N):
    S = input()
    for i in range(26):
        s = chr(ord("a")+i)
        cnt[s] = min(S.count(s), cnt[s])

res = ""
for i in range(26):
    s = chr(ord("a")+i)
    res += s*cnt[s]

print(res)