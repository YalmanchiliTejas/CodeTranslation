N = int(input())

S = input()

K = int(input())

ans = []
target = str(S[K-1])

for i in range(N):
    if S[i] == target:
        ans.append(target)
    else:
        ans.append('*')

ans = ''.join(ans)

print(ans)