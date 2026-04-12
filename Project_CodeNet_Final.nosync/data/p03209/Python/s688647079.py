def p_num(n,x):
    #print("_",n,x)

    m = 2**(n+1)-1
    #print("m",m,2*m-1)

    if n==0:
        return 1
    else:
        if x==1:
            return 0
        elif x==2*m-1:
            return m
            
        if x < m:
            #print("::1")
            return p_num(n-1, x-1)
        elif x > m:
            #print("::2")
            return (m-1)//2 + 1 + p_num(n-1, x-m)
        else:
            #print("::3")
            return (m-1)//2 + 1


n, x = map(int, input().split())

print(p_num(n,x))
