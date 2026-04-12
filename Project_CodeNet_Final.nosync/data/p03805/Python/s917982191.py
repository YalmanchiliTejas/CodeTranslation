import itertools

def path(n):
    l = len(n)
    i = 0
    while i < l - 1:
        a = n[i]
        b = n[i + 1]

        if a < b:
            c = (a, b)
        else:
            c = (b, a)

        for m in C:
            if m == c:
                break
        else:
            return False
        i += 1
    return True

N, M = map(int, input().split())
C = []
i = 0
while i < M:
    C += [tuple(map(int, input().split()))]
    i += 1

i = 0
l = range(1, N + 1)
for n in itertools.permutations(l, N):
    if n[0] != 1:
        break
    if path(n) == True:
        i += 1
print(str(i))