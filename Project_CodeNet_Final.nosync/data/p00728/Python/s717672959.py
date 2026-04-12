while True:
    n = int(input())
    if n == 0:
        break
    i = [int(input()) for i in range(n)]
    print((sum(i) - min(i) - max(i)) // (n - 2))
