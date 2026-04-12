H, W = map(int, input().split())
a = [list(input()) for i in range(H)]
jud = [0] * W

for i in a:
    for j in range(W):
        if i[j] == '#':
            jud[j] += 1
        else:
            continue

b = [i for i in a if '#' in i]

for i in range(len(b)):
    ans = ''
    for j in range(W):
        if jud[j] != 0:
            ans += b[i][j]
        else:
            continue
    print(ans)