n = int(input())

a = list(map(int, input().split()))

def num_left(pos):
	if pos % 2 == 0:
		return (n - pos) // 2 + 1
	else:
		return (n - pos - 1) // 2 + 1

d = [{} for i in range(n)]
for i in range(n):

	if i < 2:
		d[i][0] = 0
		d[i][1] = a[i]

	else:			
		left = num_left(i + 2)
		#print("i = ", i, left)
		j = i - 2
		while j >= 0:
			max_count = max(d[j].keys())
			
			if max_count + left + 1	 < n // 2: 
				break

			else: 
				for count, v in d[j].items():
					#print(count, v)
					if count + left + 1 >= n // 2:
						if count + 1 in d[i]:
							d[i][count + 1] = max(d[i][count + 1], v + a[i])
						else:
							d[i][count + 1] = v + a[i]							
			j -= 1

		if 1 + left >= n // 2:
			d[i][0] = 0

best = None
for i in range(n):
	for count, result in d[i].items():
		if count == n // 2:
			if best is None:
				best = result
			else:
				best = max(best, result)

#print(d)
print(best)
