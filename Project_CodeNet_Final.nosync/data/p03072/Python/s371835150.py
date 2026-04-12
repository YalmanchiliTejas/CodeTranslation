N = int(input())
H = list(int(i) for i in input().split())

count = 0
highest = 0
for j in range(0, N):
    if highest <= H[j]:
        count += 1
        highest = H[j]
print(count)