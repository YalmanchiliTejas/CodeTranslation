N, = map(int, input().split())
Xs = list(map(int, input().split()))
Ys = sorted(Xs)
for i in range(N):
    if Xs[i] > Ys[N//2-1]:
        print(Ys[N//2-1])
    else:
        print(Ys[N//2])
