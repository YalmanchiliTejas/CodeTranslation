while 1:
    n, l, r = map(int, input().split())
    if n == 0:
        break

    data = []
    for _ in range(n):
        data.append(int(input()))

    cnt = 0
    for i in range(l, r+1):
        for j, d in enumerate(data):
            if i % d == 0:
                if j % 2 == 0:
                    cnt += 1
                break
        else:
            if n % 2 == 0:
                cnt += 1

    print(cnt)

