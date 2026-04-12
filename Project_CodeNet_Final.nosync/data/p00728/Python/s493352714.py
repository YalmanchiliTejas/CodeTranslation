while True:
    n = int(input())
    if not n:
        break
    print(sum(sorted([int(input()) for _ in range(n)])[1:-1]) // (n - 2))
    

