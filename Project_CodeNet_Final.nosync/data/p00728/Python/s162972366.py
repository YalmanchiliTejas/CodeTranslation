while 1:
    n=int(input())
    if n<3:break
    print((sum(sorted([int(input()) for _ in [0]*n])[1:-1]))//(n-2))