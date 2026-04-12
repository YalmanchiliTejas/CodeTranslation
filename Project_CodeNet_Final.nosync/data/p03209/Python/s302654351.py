N,X=map(int,input().split())
Length=[1]
for i in range(1,51):
    Length.append(Length[i-1]*2+3)
def DP(N,point):
    if N == 0:
        return 1
    if point==1:
        return 0
    if 2<=point<=Length[N]//2:
        return DP(N-1,point-1)
    if point==Length[N]//2+1:
        return DP(N-1,point-2)+1
    if Length[N]//2+2<=point and\
            point <=Length[N]-1:
        return DP(N-1,point-Length[N-1]-2)+\
                DP(N-1,Length[N-1])+1
    if point==Length[N]:
        return DP(N-1,Length[N-1])*2+1
print(DP(N,X))
