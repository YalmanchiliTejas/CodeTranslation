N = int(input())
H = list(map(int, input().split()))
see = len(H)

for i in range(N):
    for j in range(i):
        if H[j] > H[i]:
            see -= 1
            break

print(see)
