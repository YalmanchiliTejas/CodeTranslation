def search(x,L,ans):
    if x<=1:
        return ans
    elif 1<x and x<=2**(L+1)-3:
        return search(x-1,L-1,ans)
    elif x==2**(L+1)-2:
        ans+=2**L-1
        return ans
    elif x==2**(L+1)-1:
        ans+=2**L
        return ans
    elif 2**(L+1)-1<x and x <= 2**(L+2)-5:
        ans+=2**L
        return search(x-2**(L+1)+1,L-1,ans)
    else:
        ans+=2**(L+1)-1
        return ans

N,X=list(map(int,input().split()))

ans=search(X,N,0)
print(ans)