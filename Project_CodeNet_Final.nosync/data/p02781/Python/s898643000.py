N=input()
K=int(input())

def rec(N,K):
    if K==0:
        return 1#N以下の数で、0以外の数が０、すなわち残りの桁が全て０になるパターン

    if len(N)<K:
        return 0
    
    lsb=int(N[-1])

    if len(N)==1:
        return lsb
   
    return rec(N[:-1],K-1)*(lsb)+rec(str(int(N[:-1])-1),K-1)*(9-lsb)+rec(N[:-1],K)
    
print(rec(N,K))