n = input()
high_list = list(map(int,input().split()))
most_highest = high_list[0]
can_count = 0

for i in high_list:
	if i>=most_highest:
		most_highest = i
		can_count +=1

print(can_count)