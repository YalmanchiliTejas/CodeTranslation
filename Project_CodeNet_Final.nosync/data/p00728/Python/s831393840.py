while True:
    n = int(input())
    slist = []
    for i in range(n):
        s = int(input())
        slist.append(s)
    
    if n==0:
        break
    
    for j in range(n):
        for k in range(n-1,0,-1):
            if slist[k-1]>slist[k]:
                slist[k-1],slist[k] = slist[k],slist[k-1]
    
    slist.pop(0)
    slist.pop(n-2)
    
    ave = sum(slist)//len(slist)
        
    print(ave)
