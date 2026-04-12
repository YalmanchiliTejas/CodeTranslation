from collections import Counter

N = int(input())
C = [None] * N
res = Counter(input())

for _ in range(N - 1):
    ok = False
    C = Counter(input())
    # print(C)
    tmp = list(res.keys())
    for r in tmp:
        if r in C:
            res[r] = min(res[r], C[r])
            ok = True
        else:
            res.pop(r)
    if ok is False:
        exit()
# print(sorted(list(res.items())))
for s in sorted(list(res.items())):
    print(s[0] * int(s[1]), end="")
print()
