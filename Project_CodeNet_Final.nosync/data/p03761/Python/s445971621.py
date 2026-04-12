n = int(input())
S = [input() for _ in range(n)]

ans = list(S[0])
for i in range(1, n):
    tmp = ''
    for s in S[i]:
        if s in ans:
            tmp += s
            ans.remove(s)
    ans = list(tmp)

print(''.join(sorted(ans)))



        


