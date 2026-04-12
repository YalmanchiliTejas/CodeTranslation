n = int(input())
S1 = input()
S = [list(input()) for _ in range(n-1)]
ans = ''

for s in S1:
    flag = 1
    for i in range(n-1):
        if s in S[i]:
            S[i].remove(s)
        else:
            flag = 0
    if flag == 1:
        ans += s

ans = list(ans)
ans.sort()
print(''.join(ans))
