N = int(input())
H = list(map(int, input().split()))

high = H[0]
counter = 0

for i in range(N):
    if H[i] >= high:
        counter += 1
        high = H[i]

print(counter)
