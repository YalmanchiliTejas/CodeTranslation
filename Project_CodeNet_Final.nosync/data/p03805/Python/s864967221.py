N, M = map(int, input().split())
matrix=[[0]*N for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    matrix[a-1][b-1]=1
    matrix[b-1][a-1]=1
import itertools 
count=0
for i in itertools.permutations(range(N)):
    if i[0]==0:
        result=1
        for j in range(N-1):
            result*=matrix[i[j]][i[j+1]]
        if result==1:
            count+=1
    else:
        break
print(count)