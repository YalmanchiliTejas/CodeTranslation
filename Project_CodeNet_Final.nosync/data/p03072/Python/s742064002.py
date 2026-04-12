n = int(input())
h_list = list(map(int, input().split()))
h_list = h_list[:n]
count = 0
last_h = 0
for index,h in enumerate(h_list):
	if last_h <= h:
		count += 1
	
	if last_h <= h:
		last_h = h

print(count)
		
	
	