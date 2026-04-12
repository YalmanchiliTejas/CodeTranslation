while True:
    n=int(input())
    if n==0:
            break
    a=[int(input()) for i in range(n)]
    print((sum(a)-max(a)-min(a))//(n-2))
