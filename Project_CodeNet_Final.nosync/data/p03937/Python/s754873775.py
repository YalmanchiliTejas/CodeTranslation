h,w=map(int,input().split())
t=[list(input())for i in range(h)]
cnt=0
for i in range(h):
    for j in range(w):
        if t[i][j]=="#":
            cnt+=1
if cnt==h+w-1:
    print("Possible")
else:
    print("Impossible")