while True:
    n=int(input())
    if n==0:exit()
    l=[ int(input()) for i in range(n) ]
    print(int((sum(l)-max(l)-min(l))/(n-2)))
