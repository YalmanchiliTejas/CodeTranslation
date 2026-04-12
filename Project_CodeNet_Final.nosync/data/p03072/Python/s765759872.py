N = int(input())
H = list(map(int, input().split()))

count = 1
max_height = H[0]

for n in range(1,N):
    if H[n] >= max_height:
        count += 1
        max_height = H[n]

print(count)
