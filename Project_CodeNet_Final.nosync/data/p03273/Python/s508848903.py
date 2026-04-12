H, W = map(int, input().split())
M = list()


for i in range(H):
    temp = input()        
    if (temp.count("#") != 0):
        M.append(temp) 


H = len(M)


list_of_col = [] 

for i in range(W):
    t = ""
    for j in range(H):
        t += M[j][i]
    if (t.count("#") != 0):
        list_of_col.append(i)


for i in range(H):
    for j in range(W):
        if j in list_of_col:
            print(M[i][j],end="")
    print()