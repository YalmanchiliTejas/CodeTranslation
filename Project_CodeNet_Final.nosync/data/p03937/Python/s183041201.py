H,W=[int(x) for x in input().split()]

A = [list(map(lambda x: x=="#" ,input())) for _ in range(H)]

#print(A)


try:
    for i in range(H):
        for j in range(W):
            if A[i][j]:
                start=i,j
                raise
except:
    pass


def a(i,j):
    if i<H and j<W:
        return A[i][j]
    return False

tmp =start
used = [start]
while True:
    #print(tmp)
    i,j =tmp
    if a(i+1,j):
        tmp = i+1,j
        used.append(tmp)
        continue
    if a(i,j+1):
        tmp = i ,j+1
        used.append(tmp)
    else:
        break

for i in range(H):
    for j in range(W):
        if A[i][j]:
            if (i,j) in used:
                continue
            else:
                #print(i,j)
                print("Impossible")
                exit()
print("Possible")
