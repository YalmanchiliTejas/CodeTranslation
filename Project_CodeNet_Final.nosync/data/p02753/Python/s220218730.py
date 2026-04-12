
#ライブラリインポート
from collections import defaultdict

con = 10 ** 9 + 7
#入力受け取り
def getlist():
	return list(map(int, input().split()))

#処理内容
def main():
	S = list(input())
	if S.count("A") == 3 or S.count("B") == 3:
		print("No")
	else:
		print("Yes")



if __name__ == '__main__':
	main()