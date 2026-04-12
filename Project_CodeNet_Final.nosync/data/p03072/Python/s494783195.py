n = int(input())
H = list(map(int, input().split()))
count = 1
m = H[0]
for i in range(1, n):
    if H[i] >= m:
        count += 1
    m = max(m, H[i])
print(count)