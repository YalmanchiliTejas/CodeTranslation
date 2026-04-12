#設定
import sys
input = sys.stdin.buffer.readline

#ライブラリインポート
from collections import defaultdict

#入力受け取り
def getlist():
	return list(map(int, input().split()))

#処理内容
def main():
	N, M = getlist()
	if N == M:
		print("Yes")
	else:
		print("No")


if __name__ == '__main__':
	main()