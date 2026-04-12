n = int(input())
h = list(map(int, input().split()))
count = 0
j = 0
for i in range(n):
    if h[i] >= j:
        count += 1
        j = h[i]
print(count)