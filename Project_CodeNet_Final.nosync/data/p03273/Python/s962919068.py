a, b = map(int, input().split())
A = [list(input().split()) for i in range(a)]

lines = []
for j in A:
    for k in j:
        if "#" in k:
            lines.append(k)
lines_t = ["".join(list(i)) for i in zip(*lines)]
B = []
for g in lines_t:
    if "#" in g:
        B.append(g)
C = []
C = ["".join(list(i)) for i in zip(*B)]
for v in C:
    print(v)
