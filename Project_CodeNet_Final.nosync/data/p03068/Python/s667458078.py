_ = int(input().strip())
S = input().strip()
K = int(input().strip())

print(''.join([c if c == S[K-1] else '*' for c in S]))