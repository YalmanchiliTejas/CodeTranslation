N = input()
S = input()
K = int(input())

t = S[K-1]
for i in range(len(S)):
    print(S[i] if S[i]==t else '*', end='')