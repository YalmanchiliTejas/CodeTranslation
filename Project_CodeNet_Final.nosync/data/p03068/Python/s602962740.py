N = int(input())
S = input()
K = int(input()) - 1

ans = list()
for c in S:
    if c == S[K]:
        ans.append(c)
    else:
        ans.append('*')

print(''.join(ans))