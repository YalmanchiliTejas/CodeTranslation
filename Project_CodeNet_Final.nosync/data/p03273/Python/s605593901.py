import sys
input= lambda: sys.stdin.readline().rstrip()
def pin(type=int):
    return map(type,input().split())

#%%code
def resolve():
    H,W=pin()
    maze=[list(input()) for oo in range(H)]
    vacanth=[]
    vacantw=[]
    for h in range(H):
        if "#" not in maze[h]:vacanth.append(h)
    for w in range(W):
        flag=1
        for h2 in range(H):
            if maze[h2][w]=="#":
                flag=0
                break
        if flag==1:vacantw.append(w)

    for i in range(H):
        if i in vacanth:continue
        temp=""
        for j in range(W):
            if j in vacantw:continue
            temp+=maze[i][j]
        print(temp)
    
#%%submit! 
resolve()