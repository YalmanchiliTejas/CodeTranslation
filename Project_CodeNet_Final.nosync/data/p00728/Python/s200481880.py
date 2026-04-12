while True:
    n = int(raw_input())

    if n == 0:
        break

    L = [int(raw_input()) for _ in range(n)]

    print (sum(L) - max(L) - min(L)) / (n - 2)

