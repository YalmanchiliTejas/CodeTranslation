def levelup(X,N):
    if N==0 and X!=0:
        return 1
    if X==0:
        return 0
    elif X<2**(N+1)-1:
        return levelup(X-1,N-1)
    elif X<2**(N+2)-3:
        return 2**N - 1 + levelup(X-2**(N+1)+1,N-1) + 1
    elif X==2**(N+2)-3:
        return 2**(N+1) - 1

N,X=list(map(int,input().split()))

print(levelup(X,N))