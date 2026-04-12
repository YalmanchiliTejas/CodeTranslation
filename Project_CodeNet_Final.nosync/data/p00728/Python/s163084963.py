while True:
    n = int(input())
    if n ==0:
        break
    else:
        list0=[]
        i=0
        for i in range(n):
            list0.append(int(input()))    
        list0.remove(max(list0))
        list0.remove(min(list0))
        s=sum(list0)
        a = n-2
        print(s//a)
        i=i+1

