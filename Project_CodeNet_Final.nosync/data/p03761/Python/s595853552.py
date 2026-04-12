from collections import Counter
n = int(input())
s = [Counter(input()) for _ in range(n)]

ans = ""
for x in ([chr(i) for i in range(97, 97+26)]):
    tmp = 100
    for S in s:
        if x in S.keys():
            tmp = min(tmp, S[x])
        else:
            tmp = 100
            break
    if tmp != 100:
        ans += x * tmp

print(ans)