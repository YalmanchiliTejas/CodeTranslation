import sys
input = sys.stdin.readline

N=int(input())
A=list(map(int,input().split()))

SCORE=[[None for i in range(N+1)] for j in range(N+1)]

def score(i,j,k,l):#A[i:j)が残っているときのscore,1:Xの手番,-1:Yの手番
    #print(i,j,k,l)
    
    if SCORE[i][j]!=None:
        return SCORE[i][j]+k
    if i==j:
        SCORE[i][j]=0
        return k

        

    if l==1:
        SCORE[i][j]=max(score(i+1,j,k+A[i],-l),score(i,j-1,k+A[j-1],-l))-k
        return SCORE[i][j]+k
    if l==-1:
        SCORE[i][j]=min(score(i+1,j,k-A[i],-l),score(i,j-1,k-A[j-1],-l))-k
        return SCORE[i][j]+k



hand=N%2
for i in range(N+1):
    for j in range(N-i+1):
        score(j,j+i,0,(-1)**(j+j+i+hand))

print(SCORE[0][N])