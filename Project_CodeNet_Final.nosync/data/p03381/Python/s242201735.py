from copy import deepcopy
N = int(input())
X = [int(i) for i in input().split()]
x = deepcopy(X)
X.sort()
if N%2 == 0:
    for i in x:
        if i <= X[N//2 - 1]:
            print(X[N//2])
        else:
            print(X[N//2 - 1])
else:
    for i in x:
        if i < X[N//2]:
            print((X[N//2] + X[N//2 + 1])/2)
        elif i == X[N//2 -1]:
            print((X[N//2 - 1] + X[N//2 + 1])/2)
        else:
            print((X[N//2 - 1] + X[N//2])/2)