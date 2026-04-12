while True:
    n = int(input())
    if n == 0:
        break
    else:
        list=[]
        for i in range(n):
            a=int(input())
            list.append(a)
    print((sum(list)-max(list)-min(list))//(n-2))
