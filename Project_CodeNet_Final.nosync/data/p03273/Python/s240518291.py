H,W = map(int, input().split())
A = [input() for h in range(H)]
A = [list(a) for a in A if '#' in a]
w = 0
while w < W:
    for a in A:
        if a[w]=='#':
            break
    else:
        for a in A:
            a.pop(w)
        W -= 1
        w -= 1
    w += 1
for a in A:
    print(''.join(a))