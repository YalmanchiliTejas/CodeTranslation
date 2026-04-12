K = input()
N = len(K)
D = int(input())
Y = [0] * D
P = 10**9+7
a = 0
for i in range(N):
    nY = [0] * D
    c = int(K[i])
    for j in range(10):
        if j < c:
            nk = (j+a) % D
            nY[nk] = (nY[nk] + 1) % P

        for k in range(D):
            nk = (j+k) % D
            nY[nk] = (nY[nk] + Y[k]) % P
        
    a = (a+c) % D
    Y = nY
print((Y[0] - 1 + (a==0)) % P)