n = int(input())
h = list(map(int, input().split()))
count = 1
for i in range(1, n):
    for j in range(i-1, -1, -1):
        if h[i] < h[j]:
            break
        elif j == 0:
            count += 1
print(count)