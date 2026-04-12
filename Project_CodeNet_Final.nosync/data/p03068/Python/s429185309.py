N = int(input())
S = list(input())
K = int(input())

ans = [x if x == S[K - 1] else '*' for x in S ]
print(''.join(ans))