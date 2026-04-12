import sys
input = sys.stdin.readline

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=10**9+7
    N=I()
    A=LI()
    S=[0]*(N+1)
    for i in range(N):
        S[i+1]=(S[i]+A[i])%mod
        
    ans=0
    for i in range(N):
        a=A[i]
        s=S[-1]-S[i+1]
        ans=(ans+a*s)%mod
        
    print(ans)
        
        

main()
