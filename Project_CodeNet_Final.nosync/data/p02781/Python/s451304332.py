def nlog(n):
    for i in range(200):
        if n<10**i:
            return i-1
n=int(input())
k=int(input())

ns=nlog(n)
n1=n//10**int(ns)
#print(ns,n1,n1*10**ns)

if k==1:
    icnt=0
    for i in range(0,ns+1):
        for i1 in range(1,10):
            x=i1*10**i
            if x<=n:
                icnt=icnt+1
    print(icnt)
elif k==2:
    icnt=0
    for i in range(0,ns):
        for j in range(i+1,ns+1):
            for i1 in range(1,10):
                for j1 in range(1,10):
                    x=i1*10**i+j1*10**j
                    if x<=n:
                        icnt=icnt+1
    print(icnt)
elif k==3 and n<=122:
    icnt=0
    print(icnt)
elif k==3 and n>=123:
    icnt=0
    for i in range(0,ns):
        for j in range(i+1,ns+1):
            for i1 in range(1,10):
                for j1 in range(1,10):
                    x=n1*10**ns+i1*10**i+j1*10**j
                    if x<=n:
                        icnt=icnt+1

    icnt=icnt+int((n1-1)*ns*(ns-1)/2*9*9)
    icnt=icnt+int(ns*(ns-1)*(ns-2)/6*9*9*9)

    print(icnt)