N=int(input())
X=list(map(int, input().split()))
sortX=sorted(X)
small=sortX[int(N/2)-1]
big=sortX[int(N/2)]
if small==big:
    for i in range(0,N):
        print(small)
    exit()

for i in range(0,N):
    if X[i]>small:
        print(small)
    else:
        print(big)