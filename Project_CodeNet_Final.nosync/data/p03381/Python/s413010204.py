N = int(input())
X = list(int(i) for i in input().split())
Y = [int(i) for i in X]

X.sort()

for i in range(N):
    if Y[i] <= X[int(N/2) - 1]:
        print("%d" % X[int(N/2)])
    else:
        print("%d" % X[int(N/2) - 1])