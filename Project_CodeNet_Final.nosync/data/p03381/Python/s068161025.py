N = int(input())
X = list(map(int, input().split()))
Y = X.copy()
Y.sort()
if N % 2 == 1:
    Bmin = Y[N // 2 - 1]
    Bmid = Y[N // 2]
    Bmax = Y[N // 2 + 1]
    for i in X:
        if i < Bmid:
            print((Bmid + Bmax) / 2)
        elif i > Bmid:
            print((Bmid + Bmin) / 2)
        else:
            print(Bmid)
else:
    Bmin = Y[N // 2 - 1]
    Bmax = Y[N // 2]
    for i in X:
        if i <= Bmin:
            print(Bmax)
        elif i >= Bmax:
            print(Bmin)