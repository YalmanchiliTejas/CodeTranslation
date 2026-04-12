h, w = map(int, input().split())
a = [input() for i in range(0, h)]

while True:
    for i in range(0, h):
        if all([a[i][j]=='.' for j in range(0, w)]):
            del a[i]
            h -= 1
            break
    else:
        for j in range(0, w):
            if all([a[i][j]=='.' for i in range(0, h)]):
                for i in range(0, h):
                    a[i] = a[i][:j] + a[i][j+1:]
                w -= 1
                break
        else:
            for k in range(0, h):
                print(a[k])
            exit()