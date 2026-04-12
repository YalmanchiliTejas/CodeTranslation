N,X = map(int,input().split())
L = [1]
for i in range(50) :
    L.append(L[-1]*2+3)
def dp(n,x) :
    if x == 0 :
        return 0
    elif n == 0 :
        return 1
    else :
        if x == 1 :
            return 0
        elif x <= L[n-1]+1 :
            return dp(n-1,x-1)
        elif x == L[n-1]+2 :
            return dp(n-1,x-1)+1
        elif x <= L[n]-1 :
            return dp(n-1,x-1)+1+dp(n-1,x-L[n-1]-2)
        else :
            return dp(n-1,x-1)*2+1
ans = dp(N,X)
print(ans)
