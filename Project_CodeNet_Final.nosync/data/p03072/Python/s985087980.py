n = int(input())
h = list(map(int, input().split()))

ans = 1
ml = []

for i in range(n-1):
    ml.append(h[i])
    if h[i + 1] >= max(ml):
        ans += 1

print(ans)