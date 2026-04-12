input_nums = [int(c) for c in input().split(" ")]
h = input_nums[0]
w = input_nums[1]

count = 0

for i in range(h):
	for c in input():
		if c == "#":
			count += 1

if count == h+w-1:
	print("Possible")
else:
	print("Impossible")