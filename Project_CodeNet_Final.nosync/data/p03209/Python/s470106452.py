N,X = [int(x) for x in input().split()]
# num of Ps
B = [int((2**(n+1))-1) for n in range(N+1)]
# num of layers
C = [int((2**(n+2))-3) for n in range(N+1)]

def count(n,x):
    counter = 0
    center = int((C[n]+1)/2)
    if(n==0):
        return 1
    if(x==1):
        counter = 0
    elif(x==C[n]):
        counter = B[n]
    elif(x==center):
        counter = int((B[n]+1)/2)
    elif(x<center):
        counter = count(n-1,x-1)
    elif(x>center):
        counter = int((B[n]+1)/2) + count(n-1,x-center)
    return counter

print(count(N,X))   