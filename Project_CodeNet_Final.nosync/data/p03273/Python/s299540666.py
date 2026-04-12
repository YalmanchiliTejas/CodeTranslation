h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

for _ in range(w):
    for i, j in enumerate(a):
        if set(j) == set("."):
            a.pop(i)
    a_t = [list(x) for x in zip(*a)]
    for i, j in enumerate(a_t):
        if set(j) == set("."):
            a_t.pop(i)
    a = [list(x) for x in zip(*a_t)]

[print(*ans, sep="") for ans in a]