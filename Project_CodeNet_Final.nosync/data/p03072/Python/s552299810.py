n = int(input())
H = list(map(int, input().split()))

count = 1
max = H[0]

for i in range(1, n):
    if H[i] >= max:
        count += 1
        max = H[i]

print(count)
