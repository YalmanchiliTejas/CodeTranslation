H,W = map(int,input().split())
a = []
for _ in range(H):
    i = list(input())
    if "#" in i:
        a.append(i)
a = zip(*[i for i in zip(*a) if "#" in i])
for i in a:
    print(*i, sep="")