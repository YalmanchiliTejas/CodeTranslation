n = int(input())
S = [sorted(list(input())) for _ in range(n)]
ans = []

for i in range(len(S[0])):
    count = 0
    for j in range(n):
        if S[0][i] in S[j]:
            count += 1
    if n == count:
        for k in range(n):
            if k != 0:
                S[k].remove(S[0][i])
        ans.append(S[0][i])

print(''.join(ans))