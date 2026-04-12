i=0
while True:
    n=int(input())
    list=[]
    for i in range(n):
        s=int(input())
        list.append((s))
        if i==n-1:
            list.sort()
            list.pop(n-1)
            list.pop(0)
            ave = sum(list)//len(list)
            print(ave)
    if n==0:
        break
