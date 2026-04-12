from collections import Counter

n = int(input())
S = [input() for i in range(n)]
set_char = set([c for c in S[0]])
num_char = dict()
for s in S:
    set_tmp = set()
    for c in s:
        set_tmp.add(c)
    set_char = set_char & set_tmp
    cnt = Counter(s)
    for c in set_char:
        if c not in num_char:
            num_char[c] = cnt[c]
        elif cnt[c] < num_char[c]:
            num_char[c] = cnt[c]
res = str()
for c in set_char:
    for i in range(num_char[c]):
        res = res + c
print("".join(sorted(res)))