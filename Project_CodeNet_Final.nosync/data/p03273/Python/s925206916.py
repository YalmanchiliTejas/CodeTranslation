H, W = map(int, input().split())
lines = []

for _ in range(H):
    a = list(input())
    if a.count('.') == W:
        a = len(a) * ['!']
    lines.append(a)

for w in range(W):
    c = True
    for h in range(H):
        if lines[h][w] == '#':
            c = False
            break
    if c:
        for h in range(H):
            lines[h][w] = '!'

for l in lines:
    if l.count('!') == W:
        continue
    for c in l:
        print('' if c == '!' else c, end='')
    print()
