N = int(input())
S = input()
K = int(input())

r = [s if s == S[K-1] else '*' for s in S]
print(''.join(r))
