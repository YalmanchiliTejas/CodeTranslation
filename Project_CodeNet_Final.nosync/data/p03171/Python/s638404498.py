import sys
input = sys.stdin.readline

N=int(input())
A=list(map(int,input().split()))

SCORE=[[None for i in range(N+1)] for j in range(N+1)]

def score(i,j,k,l):#A[i:j)が残っているときのscore,1:Xの手番,-1:Yの手番

    if i==j:
        SCORE[i][j]=0
        return
        
    if SCORE[i][j]!=None:
        return SCORE[i][j]+k

    if l==1:
        SCORE[i][j]=max(SCORE[i+1][j]+A[i],SCORE[i][j-1]+A[j-1])-k

    else:
        SCORE[i][j]=min(SCORE[i+1][j]-A[i],SCORE[i][j-1]-A[j-1])-k



hand=N%2
for i in range(N+1):
    for j in range(N-i+1):
        score(j,j+i,0,(-1)**(j+j+i+hand))

print(SCORE[0][N])