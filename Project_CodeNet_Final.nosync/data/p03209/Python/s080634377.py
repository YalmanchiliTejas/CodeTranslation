N,X = map(int,input().split())
L = [1]
for i in range(N) :
    l = L[-1] + 2**(2+i)
    L.append(l)
    
def dp(n,x) :
    if x == 0 :
        return 0
    elif n == 0 :
        return 1
    elif n >= 1 :
        if x == 1 :
            return 0
        elif x <= L[n-1]+1 :
            return dp(n-1,x-1)
        elif x == L[n-1]+2 :
            return dp(n-1,L[n-1])+1
        elif x <= L[n-1]*2+2 :
            return dp(n-1,L[n-1])+1 + dp(n-1,x-L[n-1]-2)
        else :
            return dp(n-1,L[n-1])*2+1
        
print(dp(N,X))
