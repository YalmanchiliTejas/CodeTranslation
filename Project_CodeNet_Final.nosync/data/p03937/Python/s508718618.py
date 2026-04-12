import copy
h,w=map(int,input().split())

def fun(aa,x,y):
    a=copy.deepcopy(aa)

    if h<=y or w<=x:
        return False

    if y==h-1 and x==w-1:
        count = 0
        for i in a:
            count += i.count('#')
        if count==1:
            return True
        else:
            return False

    if a[y][x]!="#":
        return False

    a[y][x]="."

    if fun(a,x+1,y) or fun(a,x,y+1):
        return True

    return False

a=[["" for i in range(w)] for j in range(h)]
for i in range(h):
    s=input()
    for j in range(w):
        a[i][j]=s[j]



print("Possible" if fun(a,0,0) else "Impossible")