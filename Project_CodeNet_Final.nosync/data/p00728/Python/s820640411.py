while True:
    n=int(input())
    if n==0:
        break
    lst=[]
    for i in range(n):
        x=int(input())
        lst.append(x)
    lst.remove(min(lst))
    lst.remove(max(lst))
    x=sum(lst)//(n-2)
    print(x)
