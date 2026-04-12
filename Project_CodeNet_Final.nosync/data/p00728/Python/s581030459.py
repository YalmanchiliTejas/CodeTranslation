while 1:
    n=int(input())
    if n==0:break
    a=[int(input()) for _ in range(n)]
    print((sum(a)-max(a)-min(a))//(n-2))