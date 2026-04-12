N, K = [int(x) for x in input().split()]

count = 0

if K == 0:
    print(N**2)
    exit()

for i in range(K+1, N+1):
    count += (i - K) * (N // i)
    count += max(0, N - ((N // i) * i) - K + 1)
print(count)
