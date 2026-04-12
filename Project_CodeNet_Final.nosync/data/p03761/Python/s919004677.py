import collections
n = int(input())
S = [list(input()) for i in range(n)]
Sc = [collections.Counter(i) for i in S]


if n == 1:
    S[0].sort()
    ans = "".join(S[0])
    print(ans)
else:
    counter = Sc[0] & Sc[1]
    for i in range(2, len(Sc)):
        counter = counter & Sc[i]

    Sclist = list(counter.elements())
    Sclist.sort()
    ans = "".join(Sclist)

    print(ans)
