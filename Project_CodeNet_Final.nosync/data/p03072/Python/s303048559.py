N = int(input())
H = list(map(int, input().split()))

x = 0
count = 0

for i in range(N):
    if x <= H[i]:
        count += 1
        x = H[i]

print(count)