N=int(input())
K = int(input())
def one(N):
    n = list(str(N))
    A = (len(n)-1)*9
    A += int(n[0])
    return A

def two(N):
    n = list(str(N))
    r = len(n)
    A = (int(n[0])-1)*(r-1)*9 #r-1C1*9
    A = A + (r-2)*(r-1)*81/2  #r-1C2*81
    A = A + one(N%(10**(r-1)))
    return(A)

if K==1:
    print(int(one(N)))

elif K==2:
    print(int(two(N)))

elif K==3:
    n = list(str(N))
    r = len(n)
    A = two(10**(r-1)-1)*(int(n[0])-1)
    A = A + two(N%(10**(r-1)))
    A = A + (r-2)*(r-1)*(r-3)*81*9/6
    print(int(A))

