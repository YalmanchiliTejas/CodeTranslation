N,X=map(int,input().split())
L=[1]
P=[1]
for i in range(N):
    L.append(L[i]*2+3)
    P.append(P[i]*2+1)

def dp(cur,X,ans):
    if cur==0:
        if X==0:
            return ans
        else:
            return ans+1
    elif X==0:
        return ans
    elif X>0 and X<=1+L[cur-1]:
        return dp(cur-1,X-1,ans)
    elif X==2+L[cur-1]:
        return ans+P[cur-1]+1
    elif X>2+L[cur-1] and X<L[cur]:
        return dp(cur-1,X-L[cur-1]-2,ans+P[cur-1]+1)
    else:
        return ans+P[cur]
        
print(dp(N,X,0))