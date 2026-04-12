N = input()
S = input()
K = input()


alphabet = S[int(K)-1]
answer = ''
for n in range(int(N)):
    if S[n] == alphabet:
        answer = answer+S[n]
    else:
        answer = answer+'*'

print(answer)