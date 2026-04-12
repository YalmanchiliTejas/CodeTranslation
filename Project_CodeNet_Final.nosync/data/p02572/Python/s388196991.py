N=int(input())
A=list(map(int,input().split()))
def selfmult(x):
    return x**2
dot=sum(A)**2-sum(map(selfmult,A))
dot2=dot//2
print(dot2%(1000000007))