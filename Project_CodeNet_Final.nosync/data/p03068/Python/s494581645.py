N = int(input())
S = input()
K = int(input())

ans = []
c = S[K-1]
for s in S:
    if s!=c:
        ans.append('*')
    else:
        ans.append(c)
print(''.join(ans))