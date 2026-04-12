N = int(input())
H = list(map(int, input().split()))

k = 1
tmp = H[0]
for i in range(N-1):
    if H[i+1] >= tmp:
        k += 1
        tmp = H[i+1]
print(k)