h, w = map(int, input().split())
g = []
for _ in range(h):
    r = input()
    if r != "."*w:
        g.append(r)

gg = ["" for _ in range(len(g))]

for i in range(w):
    if "".join([g[j][i] for j in range(len(g))]) != "." * len(g):
        for j in range(len(g)):
            gg[j] += g[j][i]
print(*gg, sep="\n")