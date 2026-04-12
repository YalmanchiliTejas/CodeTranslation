from collections import Counter
n = int(input())
S = input()
alr = set(S)
temp = Counter(S)
for _ in range(n-1):
    S = Counter(input())
    alr &= set(S)
    for k, v in S.items():
        if k in alr:
            temp[k] = min(temp[k], v)
ans = []
for k in list(alr):
    for _ in range(temp[k]):
        ans.append(k)
ans.sort()
print("".join(ans))
