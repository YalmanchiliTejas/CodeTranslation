N=int(input())
S=input()
K=int(input())

a = S[K-1]
print(''.join(['*' if c != a else c for c in S]))
