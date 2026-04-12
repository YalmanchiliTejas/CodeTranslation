H,W = map(int,input().split())
def trans(x):
    if x == '.':
        return False
    else:
        return True
a = []
for i in range(H):
    v = input()
    if v == '.'*W:
        H -= 1
    else:
        a.append(v)
test = [True for j in range(W)]
d = 0
for i in range(H):
    test = [True if test[j] and a[i][j] == '.' else False for j in range(W)]
for j in range(W):
    if test[j]:
        a = [a[i][:(j-d)]+a[i][(j-d+1):] for i in range(H)]
        d += 1
for i in range(H):
    print(a[i])