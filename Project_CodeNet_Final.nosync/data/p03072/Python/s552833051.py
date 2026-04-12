#B - Great Ocean View
N = int(input())
H = list(map(int, input().split()))
ans = 0
for i in range(N):
    isOk = True
    if i != 0:
        for j in range(i):
            if H[i] < H[j]:
                isOk = False
    if isOk:
        ans += 1
print(ans)