N=int(input())
S=input()
K=int(input())
print(''.join(s if s == S[K-1] else '*'for s in S ))