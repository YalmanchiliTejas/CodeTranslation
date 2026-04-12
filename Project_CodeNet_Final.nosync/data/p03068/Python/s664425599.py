N=int(input())
S= input()
K = int(input())

s = S[K-1]

print(''.join(['*' if c!=s else s for c in S]))