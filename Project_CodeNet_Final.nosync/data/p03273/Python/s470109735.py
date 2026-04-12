H, W = map(int, input().split())

dots = [input() for _ in range(H)]

newdots = []
for dot in dots:
    if dot == '.' * W:
        pass
    else:
        newdots.append(dot)


newdots2 = list(zip(*newdots))
dots = []
for dot in newdots2:
    flag = True
    for d in dot:
        if d == '#':
            flag = False

    if flag is False:
        dots.append(dot)

newdots3 = list(zip(*dots))
for d in newdots3:
    print("".join(d))