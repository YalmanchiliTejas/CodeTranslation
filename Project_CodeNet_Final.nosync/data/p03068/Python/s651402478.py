N = int(input())
S = str(input())
K = int(input())

s = S[K - 1]
answer = []
for i, c in enumerate(S):
    if c != s:
        answer.append('*')
    else:
        answer.append(c)

print(''.join(answer))
