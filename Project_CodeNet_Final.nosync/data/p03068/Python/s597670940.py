N = int(input())
S = input()
K = int(input())

ans = ''.join(['*' if s!= S[K-1] else s for s in S])
print(ans)