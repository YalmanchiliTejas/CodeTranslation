N = int(input())
L = list(map(int, input().split()))

highest = L[0]
ans = 0

for i in range(N):
        if L[i] >= highest:
                ans += 1
                highest = L[i]

print(ans)
