h, w = map(int, input().split())
a = [input() for _ in range(h)]

b = []
for i in range(h):
    if "#" in a[i]:
        b.append(a[i])


c = [list(x) for x in zip(*b)]
ans = []
for i in range(len(c)):
    if "#" in c[i]:
        ans.append(c[i])
        
ans = [list(x) for x in zip(*ans)]
for v in ans:
    print("".join(v))