#AGC007 A
'''
問題
縦H行で横W列の盤面がある
コマははじめ左上隅のマスに置かれており，右下隅に移動した
駒は1マスずつ上下左右に動ける
駒が通ったことのあるマスが提示されるので，駒が常に右または下にしか動いていなかったどうか判定せよ
ただし通ったことのあるマスは'#',一度も通らなかったマスは'.'で与えられる

考察
各行0,1,...,i,...,H-1に対して'#'のマスが存在する範囲を[ai,bi]とする。ただし0<=ai<=bi<=W-1
このとき各0,1,...,j,...,H-2について b_j == a_(j+1) であればよい
'''

import re

H,W = map(int,input().split(' '))
A = []

ans = ''
answers = ('Possible','Impossible')

r = re.compile(r'\.*#+\.*')

for i in range(H):
	s = input()
	if len(r.findall(s)) == 1:
		A.append(s)
	else:
		#'#'が2箇所以上にわかれていたらその時点でアウト
		ans = answers[1]
		break

if ans == '':
	for i in range(H-1):
		if A[i].rfind('#') == A[i+1].find('#'):
			continue
		else:
			ans = answers[1]
			break

if ans == '':
	ans = answers[0]

print(ans)