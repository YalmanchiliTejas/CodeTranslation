H,W=map(int,input().split())
ans=0
for i in range(H):
    A=input()
    for j in range(W):
        if A[j]=="#":
            ans+=1
if ans+1==H+W:
    print("Possible")
else:
    print("Impossible")
