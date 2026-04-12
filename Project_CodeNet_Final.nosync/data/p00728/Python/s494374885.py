while True:
    n=int(input())
    if n == 0:
        break
    else:
        li1=[0]*n
    
        #t=1
        for t in range(n):  
            li1[t]=int(input())
        s=int((sum(li1)-max(li1)-min(li1))/(n-2))
        print(s)
