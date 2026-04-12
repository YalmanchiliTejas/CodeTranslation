INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))
mod=10**9+7
def do():
    n=INT()
    A=LIST()
    B=[0]*(n)
    B[0]=sum(A[1:])
    ans=0

    for i in range(1,n):
        B[i]=(B[i-1]-A[i])%mod

    for i in range(n-1):
        ans+=(A[i]*B[i])%mod
        ans=ans%mod

    print(ans)

    

    
if __name__=='__main__':
    do()