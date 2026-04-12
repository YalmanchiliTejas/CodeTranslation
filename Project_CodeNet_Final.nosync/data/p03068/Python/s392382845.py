N = int(input())
S = [c for c in input()]
K = int(input())

x = S[K - 1]
result = [c if c == x else '*' for c in S]
print(''.join(result))
