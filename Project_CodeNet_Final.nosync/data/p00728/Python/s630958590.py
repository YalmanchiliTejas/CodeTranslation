while True:
    n=int(input())
    if n==0:
        break

    s=[int(input()) for i in range(n)]
    print((sum(s)-min(s)-max(s))//(n-2))
