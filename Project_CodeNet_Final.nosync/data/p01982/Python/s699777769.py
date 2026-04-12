while True:
    n, l, r = map(int, input().split())
    if n == 0:
        break

    a = []
    for i in range(n):
        a.append(int(input()))
    a.append(1)
    cnt = 0
    for i in range(l, r+1):
        for j in range(n+1):
            if i % a[j] == 0:
                if j % 2 == 0:
                    cnt += 1
                break
    print(cnt)
