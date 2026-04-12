while 1:
    n, a, b, c, x = map(int, input().split())
    if n == 0:
        break

    target = list(map(int, input().split()))
    if x == target[0]:
        target.pop(0)
    if target == []:
        print(0)
        continue

    for i in range(10000):
        x = (a * x + b) % c
        if x == target[0]:
            target.pop(0)
            if target == []:
                print(i+1)
                break
    else:
        print(-1)

