N = int(input())
H = list(map(int, input().split()))
highest, count = 0, 0
for i in range(N):
    if highest <= H[i]:
        count += 1
        highest = H[i]
print(count)