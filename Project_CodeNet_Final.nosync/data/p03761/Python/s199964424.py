n = int(input())
S = [input() for _ in range(n)]


from collections import Counter
Alphabet = 'abcdefghijklmnopqrstuvwxyz'

A = [51 for _ in range(26)]
C = [[] for _ in range(n)]
for i, s in enumerate(S):
    C[i] = Counter(s)
    for j, a in enumerate(Alphabet):
#        print(A[j])
        A[j] = min([A[j], C[i][a]])
ans = ''
for a, c in zip(Alphabet, A):
    ans += a*c
#    print(a, c, ans)
print(ans)