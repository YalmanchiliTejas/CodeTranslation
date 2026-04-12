while True:
    n = int(input())
    if n==0: break
    a = sum(sorted([int(input()) for _ in range(n)])[1:-1])//(n-2)
    print(a)