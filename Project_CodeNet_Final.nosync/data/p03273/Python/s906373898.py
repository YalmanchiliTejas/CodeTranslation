#テストファイルで実行する時
import sys
if sys.platform =='ios':
    sys.stdin=open('input_file.txt')

#2次元的な入れ方
h,w = map(int,input().split())
l = []
for i in range(h):
	x = list(input())
	#読み込む文字列xの中に#がある場合
	if '#' in x:
		l.append(x)
	else:
		h = h - 1

test = 0

for i in range(w):
	test = 0
	for j in range(h):
		if l[j][i] == '.':
			test = test + 1
	#print(test)
	if test == h :
		for k in range(h):
			l[k][i] = ''

for i in range(h):
	print(''.join(l[i]))
