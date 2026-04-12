while True:
    n=int(input())
    if n==0:
        break
    else:
        list=[]
        for i in range(n):
            temp=int(input())
            list.append(temp)
    list.remove(max(list))
    list.remove(min(list))
    a=sum(list)//(n-2)
    print(a)
