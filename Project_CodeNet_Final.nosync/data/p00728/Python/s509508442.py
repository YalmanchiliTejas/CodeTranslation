while True:
    n = int(input())
    if n == 0:
        break
    else:
        lst=[]
        for i in range(n):
            s = int(input())
            lst.append(s)
        print((sum(lst)-max(lst)-min(lst))//(n-2)) 
