import numpy as np
def DFS(answer,matrix,color,N,i):
    if not 0 in color:
        answer[0]+=1
    for j in range(N):
        if color[j]==0 and matrix[i][j]==1:
            color[j] = 1
            DFS(answer,matrix,color,N,j)
            color[j] = 0
    
def main():
    N,M = map(int,input().split())
    S = [list(map(int,input().split())) for _ in range(M)]
    matrix = np.zeros([N,N],dtype=np.int32)
    for s in S:
        matrix[s[0]-1][s[1]-1]=1
        matrix[s[1]-1][s[0]-1]=1
    color = [0]*N
    color[0] = 1
    answer = [0]
    DFS(answer,matrix,color,N,0)
    print(answer[0])
    

if __name__=='__main__':
    main()
