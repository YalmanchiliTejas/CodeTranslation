import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

N=int(input())
A=list(map(int,input().split()))

SUM=[0]*(N+1)
for i in range(N-1,-1,-1):
    SUM[i]=SUM[i+1]

    if (N-i)%2==1:
        SUM[i]+=A[i]

#print(SUM)

ADICT=dict()

def calc(i,select):
    if ADICT.get((i,select))!=None:
        return ADICT.get((i,select))
    rest=N-i

    if rest==0 or select==0:
        ADICT[(i,select)]=0
        return 0

    if rest%2==1 and rest//2+1==select:
        ADICT[(i,select)]=SUM[i]
        return SUM[i]
    
    elif rest%2==0 and rest//2==select:
        ADICT[(i,select)]=max(calc(i+1,select),A[i]+calc(i+2,select-1))
        return ADICT[(i,select)]

    elif rest%2==1 and rest//2==select:
        ADICT[(i,select)]=max(calc(i+1,select),A[i]+calc(i+2,select-1))
        return ADICT[(i,select)]

print(calc(0,N//2))

    
