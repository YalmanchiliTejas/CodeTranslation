# B
H, W = map(int, input().split())
a = []
for _ in range(H):
    i = list(input())
    if '#' in i:
        a.append(i)
ans = zip(*[i for i in zip(*a) if '#' in i])
for s in ans:
    print(*s, sep='')