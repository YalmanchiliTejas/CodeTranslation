l = [int(i) for i in input().split()]
H = l[0]
W = l[1]

my_map = []
for i in range(H) :
	s = input()
	if (s.find('#') != -1) :
		my_map.append(list(s))

remove_col_indexes = []
for col_index in range(len(my_map[0])) :
	arr = []
	for row_index in range(len(my_map)) :
		arr.append(my_map[row_index][col_index])

	if len([s for s in arr if '#' in s]) == 0 :
		remove_col_indexes.append(col_index)

result_map = []
for row_index in range(len(my_map)) :
	row_arr = []
	for col_index in range(len(my_map[row_index])) :
		if (col_index not in remove_col_indexes) :
				row_arr.append(my_map[row_index][col_index])
	
	result_map.append(row_arr)

for i in range(len(result_map)) :
	print(''.join(result_map[i]))
	
