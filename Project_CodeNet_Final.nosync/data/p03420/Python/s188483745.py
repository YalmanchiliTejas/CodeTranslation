import sys
sys.stdin.readline
def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))
mod=10**9+7

def main():
    N,K=MI()
    ans=0
    for b in range(K+1,N+1):
        ans+=((N+1)//b)*(b-K)
        ans+=max((N+1)%b-K,0)
        #print(b,((N+1)//b)*(b-K),max((N+1)%b-K,0))
    if K==0:
        ans=N*N
        
        
    print(ans)
    
            
    


main()