n = int(input())
H = list(map(int, input().split()))

lmx = 0
count = 0
for i in range(n):
    if H[i] >= lmx:
        count += 1
        lmx = H[i]
print(count)