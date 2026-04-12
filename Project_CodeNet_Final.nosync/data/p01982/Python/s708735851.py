while True:
    n, l, r = map(int, input().split())
    if (n | l | r) == 0:
        break

    A = []

    for i in range(n):
        A.append(int(input()))

    ans = 0

    for y in range(l, r + 1):

        a = 0

        for i in range(n):
            if y % A[i] == 0:
                a = i + 1
                break

        if a != 0 and a % 2 == 1:
            ans += 1

        if a == 0 and n % 2 == 0:
            ans += 1

    print(ans)

