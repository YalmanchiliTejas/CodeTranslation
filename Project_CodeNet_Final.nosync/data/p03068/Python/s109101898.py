N = int(input())
S = input()
K = int(input())

word = S[K-1]

modify = ''
for s in S:
 if s == word:
   modify += s
 else:
   modify += '*'

print(modify) 