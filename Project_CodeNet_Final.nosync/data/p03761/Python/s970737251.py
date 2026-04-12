n = int(input())
S = []
check = True
ans = []

for i in range(n):
    data = [x for x in input()]
    data.sort()
    S.append(data)

S.sort(key=len)

for char in S[0]:
    for i in range(1, len(S)):
        if (char in S[i]):
            S[i].remove(char)
        else:
            check = False
    if (check):
        ans.append(char)
    check = True

print(''.join(ans))





