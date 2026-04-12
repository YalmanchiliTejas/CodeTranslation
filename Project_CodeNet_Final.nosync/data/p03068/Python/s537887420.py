N = int(input())
S = input()
K = int(input())

k = S[K-1]

ans = []

for i in S:
    if i == k:
        ans.append(k)
    else:
        ans.append('*')

print(''.join(ans))