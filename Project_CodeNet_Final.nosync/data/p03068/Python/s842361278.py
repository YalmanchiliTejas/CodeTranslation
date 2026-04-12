N = int(input())
S = input()
K = int(input())

char = S[K-1]
res = ''.join([char if c == char else '*' for c in S])
print(res)