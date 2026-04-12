N = int(input())
L = [''] * N
for i in range(N):
    L[i] = input()
count = []
for i in range(N):
    C = [0] * 26
    S = list(L[i])
    for j in range(len(S)):
        num = ord(S[j]) - ord('a')
        C[num] = C[num] + 1
    count.append(C)
minimum = []
for i in range(26):
    M = 100
    for j in range(N):
        if count[j][i] < M:
            M = count[j][i]
    minimum.append(M)
flag = False
result = []
for i in range(26):
    if minimum[i] > 0:
        flag = True
        for j in range(minimum[i]):
            result.append(chr(ord('a') + i))
if flag == True:
    print(''.join(result))
else:
    print('')
