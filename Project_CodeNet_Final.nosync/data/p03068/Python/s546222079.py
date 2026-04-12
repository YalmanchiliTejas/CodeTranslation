N = int(input())
S = list(input())
K = int(input())

T = [c if c == S[K - 1] else '*' for c in S]
print(''.join(T))
