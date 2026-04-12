import bisect
n = int(input())
X = tuple(map(int,input().split()))
Xs = list(X)
Xs.sort()
for x in X:
    a = bisect.bisect_left(Xs,x)
    if a >= n/2:
        print(Xs[int(n/2)-1])
    else:
        print(Xs[int(n/2)])