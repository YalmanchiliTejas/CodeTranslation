#ABC107 B
H,W = map(int,input().split(' '))
field = []

for i in range(H):
	field.append(str(input()))

def rotate(mat):
	#転置行列を返す関数
	mat_t = []
	if mat != []:
		for i in range(len(mat[0])):
			#matのいまの列数＝転置後の行数
			mat_t.append([])
		for i in range(len(mat[0])):
			#matを横方向に走査
			for j in range(len(mat)):
				#matを縦方向に走査
				mat_t[i] += mat[j][i]
		for i in range(len(mat_t)):
			mat_t[i] = ''.join(mat_t[i])
	return mat_t

def white(n):
	return '.' * n

while white(W) in field:
    field.remove(white(W))
field_t = rotate(field)
while white(len(field_t[0])) in field_t:
    field_t.remove(white(len(field_t[0])))
field_t_t = rotate(field_t)

for s in field_t_t:
	print(s)