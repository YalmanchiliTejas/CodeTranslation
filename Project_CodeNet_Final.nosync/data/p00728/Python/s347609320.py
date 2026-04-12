while 1:
    n = int(input())
    if n == 0:
        break
    s = [int(input()) for i in range(n)]
    print((sum(s)-max(s)-min(s))//(n-2))

