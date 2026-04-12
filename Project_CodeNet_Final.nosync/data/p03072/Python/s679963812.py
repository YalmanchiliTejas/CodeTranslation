N = int(input())
HList = list(map(int, input().split()))

ans = 1
maxH = HList[0]

for i in range(N - 1):
    if HList[i + 1] >= maxH:
        maxH = HList[i + 1]
        ans = ans + 1

print(ans)
