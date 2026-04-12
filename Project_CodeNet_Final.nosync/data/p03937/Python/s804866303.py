H,W=map(int,input().split())
A=[input() for _ in range(H)]

ans='Possible'
i=1
while i<H:
    j=1
    while j<W:
        if A[i][j-1]=='#' and A[i-1][j]=='#':
            ans='Impossible'
        j+=1
    i+=1

print(ans)