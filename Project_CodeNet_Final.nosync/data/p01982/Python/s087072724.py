while 1:
    n, l, r = map(int, input().split())
    if n == 0: break

    a = []
    for i in range(n):
        a.append(int(input()))

    gusu = False
    if len(a) % 2 == 0: gusu = True

    count = 0
    for x in range(l, r + 1):
        for i in range(len(a)):
            comp = a[i]
            if x % comp == 0:
                if i % 2 == 0:
                    count += 1
                    break
                else: break
        else:
            if gusu: count += 1
    print(count)

