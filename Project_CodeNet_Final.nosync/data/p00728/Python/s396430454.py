while True:
    n=int(input())
    if n<3:
        break
    lst=[int(input()) for i in range(n)]
    a=sum(lst)
    b=min(lst)
    c=max(lst)
    avg=(a-b-c)//(n-2)
    print(avg)
