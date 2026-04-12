n,k = map(int,input().split())

L = n
res = 0
while(1):
    if(L == 0):
        if(k==(n+1)):
            res += 1
        break
    bar = (n-L) + (((1<<(L+2))-3)>>1) + 1
#    print(str(L)+" "+str(k)+" "+str(bar)+" "+str(res))
    if k < bar:
        L -= 1  
    elif k == bar:
        res += (1<<L)
        break 
    else:
        res += (1<<L)
        
        k -= ((1<<(L+1)) -2)
        if(k == bar):
            k -= 1
        L -= 1
print(res)
