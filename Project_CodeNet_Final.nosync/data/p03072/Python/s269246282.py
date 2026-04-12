# B - Great Ocean View
n = int(input())
heights = list(map(int, input().split()))
highest = heights[0]
hotels = 1
for i in heights[1:]:
	if i >= highest:
		hotels += 1
		highest = i
print(hotels)