a=[]
i=0
while True:
    
    N=int(input())
    if N==0:
        break
    else:
        for i in range(N):
            n=int(input())
            a.append(n)
        a.sort()
        a.pop()     
        a.pop(0)    
        print(sum(a) // len(a))
        a.clear()
            
