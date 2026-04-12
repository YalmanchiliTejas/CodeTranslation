buses = input()
first = buses[0]
count = 0
for i in buses:
	if (i == first):
    	   count += 1
if count == len(buses):
	print("No")
else:
	print("Yes")