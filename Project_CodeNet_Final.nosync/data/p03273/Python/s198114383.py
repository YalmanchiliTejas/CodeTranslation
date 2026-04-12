H,W = (int(i) for i in input().split())

a = [0 for i in range(H)]

for i in range(H):
    a[i] = list(input())

count = 0
check = []
n = 0
for i in range(H):
    for j in range(W):
        if a[i-n][j] == '#':
            count = 1
            break
    if count == 0:
        del a[i-n]
        n += 1
    count = 0

ck = []
n = 0
for i in range(W):
    for j in range(len(a)):
        if a[j][i] == '#':
            count = 1
            break
    if count == 0:
        ck.append(i)
    count = 0

for i in ck:
    for j in range(len(a)):
        del a[j][i-n]
    n += 1

ans = ''
for i in range(len(a)):
    for j in a[i]:
        ans += j
    print(ans)
    ans = ''