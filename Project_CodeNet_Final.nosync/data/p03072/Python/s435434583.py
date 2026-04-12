N = int(input())
H = [int(_) for _ in input().split()]

result = 0

maxh = 0
for i in range(N):
    if maxh <= H[i]:
        result += 1
    maxh = max(maxh, H[i])

print(result)
