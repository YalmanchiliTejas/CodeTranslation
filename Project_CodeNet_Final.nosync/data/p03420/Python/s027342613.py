N, K = map(int, input().split(" "))

retSum = 0
for b in range(K+1, N+1):
    q = N // b
    r = N - q * b
    if r >= K and r != 0:
        if r == K: retSum += 1
        else:
            if K == 0: retSum += r - K
            else: retSum += r - K + 1
    retSum += q * (b - K)
print(retSum)