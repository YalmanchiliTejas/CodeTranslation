def abc():
    h, w = map(int, input().split())
    lines = []
    for i in range(h):
        line = list(input().rstrip())
        if '#' in line:
            lines.append(line)

    for x in reversed(range(w)):
        if len([l for l in lines if l[x] == '#']) == 0:
            for l in lines:
                l.pop(x)
    for line in lines:
        print(''.join(line))


abc()
