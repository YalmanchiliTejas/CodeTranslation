while True:    
    n=int(input())
    if n == 0:  break 
    else:  
        d=[]
        for i in range(n): 
            d.append(int(input()))
        print((sum(d)-max(d)-min(d))//(n-2))
