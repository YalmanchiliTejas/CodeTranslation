import numpy as np

def tmp(n,k):
    l = len(str(n))-1
    num = 0
    if(k == 1):
        num = 9 * l
        p = n // 10**l
        num += p
    elif(k == 2):
        for i in range(1,l):
            num += i * 81
        p = n // 10**l
        r = n % 10**l
        t = (n-r-1) % 10**(l)
        num += (p-1) * tmp(t,1) + tmp(r,1)
    elif(k == 3):
        for i in range(2,l):
            num += i * (i-1) / 2 * 729
        p = n // 10**l
        r = n % 10**l
        t = (n-r-1) % 10**(l)
        num += (p-1) * tmp(t,2) + tmp(r,2)
    return(num)



N = int(input())
K = int(input())


print(int(tmp(N,K)))