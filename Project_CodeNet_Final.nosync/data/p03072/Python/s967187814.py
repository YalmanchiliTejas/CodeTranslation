# B
n = int(input())
h = list(map(int, input().split()))

count = 1
m = h[0]
for i in range(n-1):
    if m <= h[i+1]:
        count += 1
        m = h[i+1]
print(count)