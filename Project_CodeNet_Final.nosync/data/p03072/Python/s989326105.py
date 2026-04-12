n = int(input())
m = list(map(int, input().split()))
maxH = m[0]
numH = 0
for i in range(n):
    if m[i] >= maxH:
        maxH = m[i]
        numH += 1
print(numH)