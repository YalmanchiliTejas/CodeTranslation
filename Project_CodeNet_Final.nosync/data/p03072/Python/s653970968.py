n = int(input())

hs = list(map(int, input().split()))
maxs = [0] * (n + 1)

m = 0
for i in range(n):
    m = max(m, hs[i])
    maxs[i + 1] = m

count = 0
for i in range(n):
    if maxs[i] <= hs[i]:
        count += 1

print(count)