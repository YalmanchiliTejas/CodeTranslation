H,W=map(int, input().split())
a=[list(input()) for i in range(H)]

WHITE='.'
print_row=[]
print_col=[]
for i in range(H):
    for j in range(W):
        if a[i][j] != WHITE:
            if i not in print_row:
                print_row.append(i)
            if j not in print_col:
                print_col.append(j)

for i in range(H):
    linefeed = False
    for j in range(W):
        if i in print_row and j in print_col:
            linefeed = True
            print(a[i][j], sep="", end="")
    if linefeed:
        print(sep="")
