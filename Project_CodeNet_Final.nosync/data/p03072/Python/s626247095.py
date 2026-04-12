n = int(input())
h = list(map(int, input().split()))
count = 1
max_h = h[0]
for i in range(n-1):
    if h[i+1] >= max_h:
        count += 1
        max_h = h[i+1]
print(count)