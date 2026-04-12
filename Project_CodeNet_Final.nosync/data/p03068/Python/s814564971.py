import sys

def parse(inp):
    n=int(next(inp))
    s=list(next(inp))[:-1]
    k=int(next(inp))    
    return n,s,k
  
def main(inp):
    n,s,k=inp
    
    keep=s[k-1]
    
    ans=""
    for i in range(n):
        if(s[i]==keep): ans+=s[i]
        else: ans+="*"
            
    print(ans)
    
main(parse(sys.stdin))