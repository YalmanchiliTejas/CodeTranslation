while 1:
    n = int(input())
    if n==0:
        break
    lst = []
    for i in range(n):
        lst.append(int(input()))
    lst.sort()
    del lst[0]
    del lst[n-2]
    y=sum(lst)
    print(y//(n-2))
