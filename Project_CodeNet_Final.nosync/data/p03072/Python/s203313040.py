N = int(input())
a = input()
inp = a.split()
inp = [int(i) for i in inp]

cnt = 0

for index, now in enumerate(inp):
	flag = 0
	for j in range(index):
		#注目の山より西の山の方が高い場合フラグを1にする
		if inp[j] > now:
			flag = 1
	#すべての西の山が低い場合カウントを増やす
	if flag == 0:
		cnt += 1

print(cnt)