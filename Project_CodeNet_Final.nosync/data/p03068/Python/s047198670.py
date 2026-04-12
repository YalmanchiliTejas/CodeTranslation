N = int(input())
S = input()
K = int(input())
assert len(S) == N

T = (c if c == S[K-1] else '*' for c in S)
print(''.join(T))
