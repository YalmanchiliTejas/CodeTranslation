# Tenka1 Programming Beginner Contest 2019: B – *e**** ********e* *e****e* ****e**
N = int(input())
S = input()
K = int(input())

s_k = S[K - 1]

replaced = ''
for s in S:
    replaced = replaced + '*' if s != s_k else replaced + s_k

print(replaced)