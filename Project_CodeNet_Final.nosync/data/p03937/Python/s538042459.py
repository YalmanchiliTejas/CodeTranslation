H,W = map(int,input().split(" "))
A = [0]*(H+1)
o = 0
for i in range(H):
    a = list(input())
    o += a.count('#')
    A[i] = a + ['.']

A[-1] = ['.'] * (W+1)

x = 0
y = 0
p = 1

while x < W and y < H:
    right = A[y][x+1] == '#'
    down = A[y+1][x] == '#'
    if right:
        x += 1
        p += 1
    elif down:
        y += 1
        p += 1
    else:
        break

print(['Impossible','Possible'][o == p])