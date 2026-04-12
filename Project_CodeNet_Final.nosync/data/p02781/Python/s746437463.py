N = int(input())
K = int(input())
A = 0
keta = len(str(N))
if K ==1:
    A = 9*(keta-1)
if K ==2:
    A = 9*9*(keta-1)*(keta-2)//2
if K ==3:
    A = 9*9*9*(keta-1)*(keta-2)*(keta-3)//6
nc = 1
#    print(N,K,keta,A)
while nc <= 3 and keta >=1:
        # abcd... -> 1000000 - a0000000
    T = N//(10**(keta-1))%10
#        print(T,nc)
    if T == 0:
        keta -=1
    else:
        if (nc == 1 and K==1) or (nc==2 and K==2) or (nc==3 and K==3):
            A = A + (T)
        if ((nc == 1 and K ==2) or (nc ==2 and K==3)):
            A = A + int((T-1)*9*(keta-1))
        if (nc==2 and K==2) or (nc==3 and K==3):
            A = A + 9*(keta-1)
        if (nc==1 and K ==3):
            A = A + int((T-1)*9*9*(keta-1)*(keta-2)/2)
        if (nc==2 and K==3):
            A = A + int(9*9*(keta-1)*(keta-2)/2)
        nc +=1
        keta -=1
#        print(A)
        
print(A)
