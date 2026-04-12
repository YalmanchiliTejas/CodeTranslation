N = int(input())
H = list(map(int, input().split()))

max_H = H[0]
L = [1 for i in range(N)]
for i in range(1, N):
    if H[i] >= max_H:
        L[i] = 1
    else:
        L[i] = 0
    max_H = max(H[i], max_H)

print(sum(L))
