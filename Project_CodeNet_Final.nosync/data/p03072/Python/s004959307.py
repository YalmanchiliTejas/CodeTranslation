N = int(input())
h = [0] + [int(i) for i in input().split()]

count = 1

for i in range(2, N+1):
    west_heights = h[1:i]
    if h[i] >= max(west_heights):
        count += 1

print(count)
