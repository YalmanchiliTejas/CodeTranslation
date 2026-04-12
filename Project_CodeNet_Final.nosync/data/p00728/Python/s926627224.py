while True:
    n = int(input())
    if n < 3:
        break
    print(sum(sorted([int(input()) for i in range(n)])[1:-1]) // (n - 2))