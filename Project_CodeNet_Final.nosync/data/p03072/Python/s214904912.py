n = int(input())
h = list(map(int, input().split()))
hSum = 0
for i in range(n):
    if h[i] == max(h[0:i + 1]):
        hSum += 1
print(hSum)
