# input
N = int(input())
H = list(map(int, input().split()))

# check
ocean_view = 1
max = H[0]
for i in range(1, N):
    if max <= H[i]:
        ocean_view += 1
        max = H[i]

print(ocean_view)