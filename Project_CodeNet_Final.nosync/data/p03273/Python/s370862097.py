h,w = map(int, input().split())
A = []
for i in range(h):
    s = input()
    #print('---', s)
    if not s == '.'*w:
        A.append([j for j in s])
if len(A) > 1:
    for j in range(len(A[0])-1,-1,-1):
        
        c = 0
        for i in range(len(A)-1,-1,-1):
            #print(i,j)
            if A[i][j] == '.':
                #print(A[i])
                c +=1
        if c == len(A):
            for k in range(len(A)-1,-1,-1):
                A[k].pop(j)
else:
    for l in range(len(A[0])-1,-1,-1):

        if A[0][l] == '.':
            A[0].pop(l)

for i in range(len(A)):
    print(''.join(A[i]))