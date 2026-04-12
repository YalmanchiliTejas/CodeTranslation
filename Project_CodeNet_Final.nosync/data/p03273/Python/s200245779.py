N,M=map(int,input().split())
grid=[[0 for i in range(M)] for j in range(N)]
moji=""
for i in range(N):
    moji=input()
    for j in range(len(moji)):
        grid[i][j]=moji[j:j+1]
    

X=0
Y=0
while(X<N or Y<M): # or Y<=M
    delflug=True
    if (X<N):
        for i in range(M):
            if grid[X][i]=="#":
                delflug=False
                break
        if delflug==True:
            del grid[X]
            N-=1
            X-=1
            
        X+=1    
    else:
        for i in range(N):
            if grid[i][Y]=="#":
                delflug=False
                break
        if delflug==True:
            for i in range(N):
                del grid[i][Y]
                
            M-=1
            Y-=1
            
        Y+=1    
for i in range(N):
    s="".join(grid[i])
    print(s)