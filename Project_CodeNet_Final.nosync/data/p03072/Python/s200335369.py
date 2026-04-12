n = input()
h = input().split()

sum_hotel = 0
max_height_mt = 0

for i in range(int(n)):
    if max_height_mt <= int(h[i]):
        sum_hotel += 1
    if max_height_mt <= int(h[i]):
        max_height_mt = int(h[i])

print(sum_hotel)