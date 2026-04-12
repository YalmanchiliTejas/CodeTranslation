N = int(input())
S = input()
K = int(input())
re = S[K-1]
l = ['*' if S[i] != re else re for i in range(N)]
print(''.join(l))