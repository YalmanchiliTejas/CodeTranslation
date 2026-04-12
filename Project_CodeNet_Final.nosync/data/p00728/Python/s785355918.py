import math
while True:
    x=[]
    y=0
    n=int(input())
    if n==0:
        break
    for i in range(n):
        s=int(input())
        x+=[s]
    #print(x)
    
    x.remove(max(x))
    #print(x)
    x.remove(min(x))
    #print(x)
    
    
    for j in range(n-2):
        y+=x[j]
    
    #print(y)
    
    print(
        math.floor(y/(n-2))
        )
    
    

