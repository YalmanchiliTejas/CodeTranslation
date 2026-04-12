h,w = map(int,input().split())
a = []
a.append("."*(w+2))
for i in range(h):
    a.append("." + input() + ".")
a.append("."*(w+2))
ans = "Possible"
for i in range(h+2):
    for j in range(w+2):
        if a[i][j] == "#":
            if i==1 and j==1:
                if [a[i+1][j],a[i][j+1]].count("#")!=1:
                    ans = "Impossible"
            elif i==h and j==w:
                if [a[i-1][j],a[i][j-1]].count("#")!=1:
                    ans = "Impossible"
            else:
                if [a[i-1][j],a[i][j-1]].count("#")!=1 or [a[i+1][j],a[i][j+1]].count("#")!=1:
                    ans = "Impossible"
print(ans)