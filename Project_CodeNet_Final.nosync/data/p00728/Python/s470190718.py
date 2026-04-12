while True:
    n=int(input())
    list=[]
    if n==0:
        break
    for i in range(n):
        list.append(int(input()))
    list.sort()
   
    ave=(sum(list)-list[0]-list[-1])//(n-2)
    print(ave)

