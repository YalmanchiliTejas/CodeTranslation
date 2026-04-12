N = int(input())
s = input()

def next(p, c, s):
    if p == 'S' and c == 'S':
        return 'S' if s == 'o' else 'W'
    elif p == 'S' and c == 'W':
        return 'W' if s == 'o' else 'S'
    elif p == 'W' and c == 'S':
        return 'W' if s == 'o' else 'S'
    elif p == 'W' and c == 'W':
        return 'S' if s == 'o' else 'W'
    else:
        return None

flag = False
for p, c in [('S', 'S'), ('S', 'W'), ('W', 'S'), ('W', 'W')]:
    r = p + c
    for i in range(1, N-1):
        r += next(r[-2], r[-1], s[i])

    if next(r[-2], r[-1], s[N-1]) == r[0] and next(r[-1], r[0], s[0]) == r[1]:
        flag = True
        print(r)
        break

if not flag:
    print(-1)
