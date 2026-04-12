while 1:
    n=int(input())
    if n==0:break
    print((sum(sorted([int(input()) for _ in range(n)])[1:-1]))//(n-2))