N = int(input())
S = input()
K = int(input())

t = S[K - 1]

print(''.join([s if s == t else '*' for s in S]))
