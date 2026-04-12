N = int(input())
S = input()
K = int(input())

print(*[c if c == S[K-1] else '*' for c in S], sep='')
