H,W = map(int,input().split())

squares=[]

for i in range(H):
    squares.append(list(input()))

# rows
    
for i in range(H-1,-1,-1):
    if '#' not in squares[i]:
        del squares[i]
        
# columns
check_col =[]  
    
for j in range(W):
    flag=True
    for i in range(len(squares)):
        if squares[i][j] == '#':
            flag = False
    if flag:
        check_col.append(j)

check_col.sort(reverse=True)

for j in check_col:
    for i in range(len(squares)):
        del squares[i][j]
        
# print

for i in range(len(squares)):
    print(''.join(squares[i]))
        


