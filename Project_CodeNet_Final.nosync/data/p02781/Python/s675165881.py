N=input()
K=int(input())
m=len(N)
a=0
if K==3:
    for i in range(1,m-2):
        a+=i*(i+1)
    a//=2
    a*=729
    for i in range(1,10):
        for j in range(1,10):
            for k in range(1,10):
                for b in range(m-2):
                    for c in range(m-2-b):
                        if N>=str(i)+"0"*b+str(j)+"0"*c+str(k)+"0"*(m-3-b-c):
                            a+=1
elif K==1:
    if int(N)<10:
        a=int(N)
    else:
        a=9
        for i in range(2,m):
            a+=9
        for i in range(1,10):
            if N>=str(i)+"0"*(m-1):
                a+=1
else:
    for i in range(1,m-1):
        a+=i
    a*=81
    for i in range(1,10):
        for j in range(1,10):
            for k in range(m-1):
                if N>=str(i)+"0"*k+str(j)+"0"*(m-2-k):
                    a+=1
print(a)