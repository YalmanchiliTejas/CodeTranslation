while True:
    n=int(input())
    if n==0:
        break
    A=[int(input()) for i in range(n)]
    B=((sum(A)-max(A)-min(A))//(n-2))
    print(B)
