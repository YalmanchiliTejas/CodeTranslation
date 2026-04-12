h, w = map(int, input().split())

A = []
B = ["."] * (w + 2)
A.append(B)
temp = 0
for i in range(h):
    T = ['.'] + list(input()) + ['.']
    A.append(T)
    temp += T.count('#')
A.append(B)

t = 1
x = 1
y = 1
ans = 0
while t:
    if A[x][y] == '#':
        C = []
        C.append(A[x][y + 1])
        C.append(A[x+1][y])
        if C.count('#') > 1:
            t = 0
        else:
            A[x][y] = '?'
            if A[x][y+1] == '#':
                y = y + 1
            else:
                x = x + 1
            ans += 1
    else:
        t = 0

print("Possible" if ans == temp else "Impossible")