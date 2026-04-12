while True:
    n = int(input())
    if n == 0:
        break
    else:
        list=[]
        for i in range(n):
            list.append(int(input()))
            list.sort()
    print(sum(list[1:n-1])//(n-2))
