h , w = map(int,input().split())
ma = [list(input()) for i in range(h)]
ans = []
for i in range(h):
    kar = []
    for j in range(w):
        if ma[i][j] =="#":
            kar.append(j)
    ans.append(kar)


for i in range(h-1):
    if max(ans[i]) != min(ans[i+1]):
        print("Impossible")
        exit()
        
print("Possible")