import copy
N = int(input())
X = list(map(int,input().split()))
Y = copy.copy(X)
X.sort()
index = N//2
for i in range(N):
    print(X[index] if X[index]>Y[i] else X[index-1])