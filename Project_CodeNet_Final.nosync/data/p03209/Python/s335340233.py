Pat=[1]
All=[1]
for i in range(51):
    Pat.append(Pat[i]*2+1)
    All.append(All[i]*2+3)

N,X=map(int,input().split())

def saiki(N,X):
    if N==0:
        if X<=0:
            return 0
        else:
            return 1
    elif X<=All[N-1]+1:
        return saiki(N-1,X-1)
    elif X<=All[N]-1:
        return Pat[N-1]+1+saiki(N-1,X-2-All[N-1])
    else:
        return Pat[N]
        
print(saiki(N,X))