h, w =  [ int(v) for v in input().split() ]
column_list = []
row_list = []
field = [ None for i in range(h) ]
space_column = "." * w
space_row = "." * h
for i in range(h):
	s = input()
	field[i] = s
	if s != space_column:
		column_list.append(i)

for i in range(w):
	s = "".join([field[j][i] for j in range(h)])
	if s != space_row:
		row_list.append(i)


for i in column_list:
	print("".join([ field[i][j] for j in row_list ]))