from itertools import permutations
n,m=map(int,input().split())
A=[list(map(int, input().split())) for i in range(m)]
N=list(permutations([i+2 for i in range(n-1)]))
count=0
for k in range(len(N)):
    flag=0
    for i in range(n-1):
        if i ==0:
            for j in range(m):
                if set([N[k][0],1])== set(A[j]):
                    flag+=1
            if flag==n-1:
                count+=1
        else:
            for j in range(m):
                if set([N[k][i],N[k][i-1]])== set(A[j]):
                    flag+=1
            if flag==n-1:
                count+=1
print(count)