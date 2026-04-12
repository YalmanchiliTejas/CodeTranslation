N=int(input())
H=list(map(int,input().split()))

X=1
for i in range(1,N):
    if max(H[:i])<=H[i]:
        X+=1

print(X)