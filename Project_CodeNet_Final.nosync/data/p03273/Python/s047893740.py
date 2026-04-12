H, W = map(int, input().split())
a=[]
for i in range(H):
    x = input()
    if "#" in x:
        a.append(list(x))
b=[i for i in zip(*a)]
c=[]
for i in range(W):
    if "#" in b[i]:
        c.append(b[i])
c=[i for i in zip(*c)]
for i in c:
    print(*i, sep="")