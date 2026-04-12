#n=int(input())
h,w=map(int,input().split())
#l=list(map(int,input().split()))
l=[list(input()) for i in range(h)]

# まずは行について確認する
row_compare=['.' for i in range(w)]
save_rows=[]
for row in range(h):
    if not l[row]==row_compare:
        save_rows.append(row)

newl=[l[row] for row in save_rows]

h=len(newl)
#次は列
save_col=[]
col_compare=["." for i in range(h)]
for col in range(w):
    temp=[]
    for row in range(h):
        temp.append(newl[row][col])
    if not temp==col_compare:
        save_col.append(col)

ansl=[]
for row in range(h):
    temp=[]
    for col in range(w):
        if col in save_col:
            temp.append(newl[row][col])
    ansl.append(temp)

for row in ansl:
    print(*row,sep="")