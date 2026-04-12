for x in range(20):
    a=int(input())
    if a==0: break
    
    lst = []
    for x in range(a):
        lst.append(int(input()))
    b=min(lst)
    c=max(lst)
    lst.remove(b)
    lst.remove(c)
    d=sum(lst)
    ave=d//(a-2)
    print(ave)
        
