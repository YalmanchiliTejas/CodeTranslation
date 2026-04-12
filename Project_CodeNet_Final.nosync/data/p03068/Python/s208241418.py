N = int(input())
S = input()
K = int(input())

ans = []
for s in S:
    if s is not S[K-1]:
        ans.append('*')
    else:
        ans.append(s)
print(''.join(ans))
