N = int(input())
S = input()
K = int(input())

print(''.join('*' if S[i] != S[K-1] else S[i] for i in range(N)))