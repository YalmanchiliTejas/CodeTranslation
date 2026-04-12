N = int(input())
H = list(map(int, input().split()))

res = 1
for i in range(1, N):
    if all(H[j] <= H[i] for j in range(0, i)):
        res += 1
print(res)