N = int(input())
X = list(map(int, input().split()))

Y = sorted(X)

l = Y[N//2-1]
r = Y[N//2]

for i in X:
    if l >= i:
        print(r)
    else:
        print(l)