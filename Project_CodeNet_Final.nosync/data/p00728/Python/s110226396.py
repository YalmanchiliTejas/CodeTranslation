while True:
    n=int(input())
    if n==0:
        break
    data=[int(input()) for _ in range(n)]
    a=max(data)
    b=min(data)
    s=sum(data)
    s=s-a-b
    s=s//(n-2)
    print(s)
