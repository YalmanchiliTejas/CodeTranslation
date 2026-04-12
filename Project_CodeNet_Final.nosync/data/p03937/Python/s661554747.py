# AGC 007: A – Shik and Stone
h, w = [int(s) for s in input().split()]
a = [input() for _ in range(h)]

the_number_of_stones = 0

for i in range(h):
    the_number_of_stones += a[i].count('#')

print('Possible' if the_number_of_stones == h + w - 1 else 'Impossible')