import collections

n = int(input())
si = [[_ for _ in input()] for _ in range(n)]

Intsec = collections.Counter(si[0])

for s in si:
    Intsec = Intsec & collections.Counter(s)

ans = list(Intsec.elements())
ans.sort()

print(''.join(ans))