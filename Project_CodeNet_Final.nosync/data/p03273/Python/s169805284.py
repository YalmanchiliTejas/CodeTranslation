h, w = map(int, input().split())
a = [input() for w in range(h)]

for i in range(h)[::-1]:
    if "#" not in a[i]:
        del a[i]
        h -= 1

n = []
for j in range(w):
    m = ["".join(t[j] for t in a)]
    if "#" in m[0]:
        n += m

for k in range(h):
    print("".join(u[k] for u in n))
