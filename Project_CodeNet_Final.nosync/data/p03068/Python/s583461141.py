N = int(input())
S = input()
K = int(input())
S = list(S)
t = S[K-1]
U = [s if s == t else '*' for s in S]
U = ''.join(U)
print(U)