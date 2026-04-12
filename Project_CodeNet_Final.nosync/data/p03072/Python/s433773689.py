import sys

def main(inp):
    N=int(next(inp))
    H=list(map(int,next(inp).split()))
    
    ans=0
    high=0
    for i in range(N):
        if(high<=H[i]): ans+=1
        high=max(high,H[i])
    
    return ans
    
print(main(sys.stdin))