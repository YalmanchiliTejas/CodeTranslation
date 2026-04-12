n, *X = map(int, open(0).read().split())
Y = sorted(X)
m = (n-1) // 2

for x in X:
    med = Y[m]
    if med >= x:
        med = Y[m+1]
    print(med)