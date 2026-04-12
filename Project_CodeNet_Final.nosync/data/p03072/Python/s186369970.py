n = int(input())
h =list(map(int, input().split()))
result = 0
for i in range(len(h)):
    if h[0] <= h[i]:
        h[0] = h[i]
        result += 1
print(result)
