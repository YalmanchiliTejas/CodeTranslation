
def compression(init, matrix):
	
	mir = []
	
	for row in matrix:
		if "#"in row:
			mir.append(row)
	matrix = []
	
	mir = list(map(list, zip(*mir)))
	
	for row in mir:
		if "#"in row:
			matrix.append(row)
		
	matrix = list(map(list, zip(*matrix)))	
			
	
	return matrix


init = input().split(" ")
init = [int(c) for c in init]

matrix = [[] for j in range(init[0])]

for j in range(init[0]):
	matrix[j] = input()

result = compression(init, matrix)
for row in result:
	print("".join(row))