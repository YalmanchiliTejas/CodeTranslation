N = int(input())
S = input()
K = int(input())

Sk = S[K - 1]
print(''.join([s if s == Sk else '*' for s in S]))
