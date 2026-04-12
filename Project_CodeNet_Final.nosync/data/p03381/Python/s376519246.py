N = int(input())

X = list(map(int,input().split()))
sortX = sorted(X)

A = sortX[(N//2)-1]
B = sortX[(N//2)]

for x in X:
    if x<B: print(B)
    else: print(A)