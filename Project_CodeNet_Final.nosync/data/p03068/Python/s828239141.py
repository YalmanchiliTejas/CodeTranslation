if __name__ == '__main__':
	N = int(input())
	S = input()
	K = int(input())
	token = S[K-1]
	ans = ''
	for i in range(N):
		if(S[i] != token):
			ans+='*'
		else:
			ans+=S[i]

	print(ans)