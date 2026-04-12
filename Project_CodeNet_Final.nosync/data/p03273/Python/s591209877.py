import copy
H,W = map(int,input().split())
A = [list(input().strip()) for _ in range(H)]
while True:
    flag = 0
    for i in range(len(A)-1,-1,-1):
        fr = 0
        for j in range(len(A[0])):
            if A[i][j]=="#":
                fr = 1
                break
        if fr==0:
            B = [[0 for _ in range(len(A[0]))] for _ in range(len(A)-1)]
            for i1 in range(len(A)):
                if i1<i:
                    for j1 in range(len(A[0])):
                        B[i1][j1] = A[i1][j1]
                elif i1>i:
                    for j1 in range(len(A[0])):
                        B[i1-1][j1] = A[i1][j1]
            A = copy.deepcopy(B)
            flag = 1
    for j in range(len(A[0])-1,-1,-1):
        fc = 0
        for i in range(len(A)):
            if A[i][j]=="#":
                fc=1
                break
        if fc==0:
            B = [[0 for _ in range(len(A[0])-1)] for _ in range(len(A))]
            for j1 in range(len(A[0])):
                if j1<j:
                    for i1 in range(len(A)):
                        B[i1][j1] = A[i1][j1]
                elif j1>j:
                    for i1 in range(len(A)):
                        B[i1][j1-1] = A[i1][j1]
            A = copy.deepcopy(B)
            flag = 1
    if flag==0:break
for i in range(len(A)):
    print("".join(A[i]))