h,w=map(int,input().split())
A=[list(input()) for i in range(h)]
cnt=0
for i in range(h):
    cnt +=A[i].count("#")
print("Possible" if cnt==h+w-1 else "Impossible")