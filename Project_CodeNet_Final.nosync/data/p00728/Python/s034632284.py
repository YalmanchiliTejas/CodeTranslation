while True:
    n=int(input())
    if n==0:
        break
    else:
        listA=[] 
        for i in range(n):
            listA.append(int(input()))
        print((sum(listA)-max(listA)-min(listA))//(n-2))
