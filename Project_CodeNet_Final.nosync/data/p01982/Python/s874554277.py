while True:
    n, r, l = map(int, input().split())
    if n == 0:
        break
    else:
        a = []
        for i in range(n):
            a.append(int(input()))
        a.append(1)
        count = 0
        for i in range(r, l + 1):
            for j in range(n + 1):
                if i % a[j] == 0:
                    if j % 2 == 0:
                        count += 1
                    break
        print(count)
