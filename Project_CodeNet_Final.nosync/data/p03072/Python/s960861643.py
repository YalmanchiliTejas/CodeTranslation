N = int(input())
HEIGHTS = list(map(int, input().split()))
result = 0

for i in range(N):
    if HEIGHTS[i] == max(HEIGHTS[:i+1]):
        result += 1
    else:
        continue

print(result)