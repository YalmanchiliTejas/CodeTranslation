# _*_ coding:utf-8 _*_
#  Atcoder_Beginners_Contest114-A
#  https://beta.atcoder.jp/contests/abc114/tasks/abc114_a


def check_753(s):

	if(s == '7' or s=='5' or s=='3'):
		answer = "YES"
	else:
		answer = "NO"
	return answer


if __name__ == '__main__':
	problemStr=input()
	answerStr=check_753(problemStr)
	print(answerStr)