N = int(input())
S = input()
K = int(input()) - 1

ans = []
for c in S:
    if c != S[K]:
        ans.append('*')
    else:
        ans.append(c)

print(''.join(ans))
