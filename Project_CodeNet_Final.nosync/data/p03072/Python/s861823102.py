# ABC 124: B – Great Ocean View
n = int(input())
h = [int(s) for s in input().split()]

number_inns_can_see_ocean = 0
highest = h[0]

for height_of_inn in h:
    if height_of_inn >= highest:
        number_inns_can_see_ocean += 1
        highest = height_of_inn

print(number_inns_can_see_ocean)