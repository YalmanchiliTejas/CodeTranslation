n = int(input())
h = list(map(int, input().split()))

hotels = 1

for i in range(1, n):
    if max(h[:i]) <= h[i]:
        hotels += 1

print(hotels)