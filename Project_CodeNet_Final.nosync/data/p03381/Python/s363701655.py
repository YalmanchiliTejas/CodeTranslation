N=int(raw_input())
X=map(int, raw_input().split())
Y=sorted(X)
m1=Y[N/2-1]
for x in X:
    if x<=m1:
        print Y[N/2]
    else:
        print m1
