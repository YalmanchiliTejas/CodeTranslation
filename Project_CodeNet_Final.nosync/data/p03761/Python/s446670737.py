import collections
n = int(input())
S = [list(input()) for i in range(n)]

S.sort(key=lambda x: len(x))
table = collections.defaultdict(int)

len_s = len(S[0])
for i in range(1, n):
    for x in S[0]:
        if x in S[i]:
            S[i].pop(S[i].index(x))
        else:
            S[0].pop(S[0].index(x))

S[0].sort()
print("".join(S[0]))
