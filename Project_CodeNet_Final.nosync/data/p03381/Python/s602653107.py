import copy

N = int(input())
X = []
X = [int(i) for i in input().split()]

Y = copy.deepcopy(X)
Y.sort()

largeMedian = Y[int(N / 2)]
smallMedian = Y[int(N / 2)-1]

for i in range(N):
    if X[i] <= smallMedian:
        X[i] = largeMedian
    else:
        X[i] = smallMedian

for i in range(N):
    print(X[i])
