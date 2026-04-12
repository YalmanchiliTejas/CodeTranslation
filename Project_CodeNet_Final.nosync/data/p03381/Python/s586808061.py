N = int(input())
X = [int(i) for i in input().split()]
Y = sorted(X)
left = Y[N//2 -1]
right = Y[N//2 ]
for x in X:
    if x<=left:
        print(right)
    else:print(left)