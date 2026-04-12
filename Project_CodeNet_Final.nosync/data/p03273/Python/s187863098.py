H,W = map(int,input().split())
b = []
for i in range(H):
    a = input()
    if "#" in a:
        b.append(a)

c = [i for i in range(W)]
for i in range(len(b)):
    for j in range(W):
        if b[i][j] == "#":
            if j in c:
                c.remove(j)
c.sort()
cnt = 0
for i in range(len(c)):
    c[i] -= cnt
    cnt += 1
for i in c:
    for j in range(len(b)):
        b[j] = b[j][:i]+b[j][i+1:]
for i in range(len(b)):
    print(b[i]) 