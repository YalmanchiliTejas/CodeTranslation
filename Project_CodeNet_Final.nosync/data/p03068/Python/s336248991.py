N = int(input())
S = input()
K = int(input())

s = S[K-1]

answer = ''
for i in range(N):
    if S[i] != s:
        answer += '*'
    else:
        answer += s
print(answer)
