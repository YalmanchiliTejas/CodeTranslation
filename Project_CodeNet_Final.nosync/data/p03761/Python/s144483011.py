N = int(input())
S = []
for i in range(N):
    S.append(str(input()))
import collections
L = []
for s in S:
    S_dict = collections.Counter(s)
#     print(S_dict.keys())
    for i in S_dict.keys():
        L.append(i)
# print(L)

ans = ""
for i in "abcdefghijklmnopqrstuvwxyz":
    if L.count(i) == N:
        check = 10 ** 18
        for j in S:
            check = min(j.count(i), check)
        ans += i * check
print(ans)