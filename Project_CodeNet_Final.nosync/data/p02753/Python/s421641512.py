S = input()

ans = 'No'
for i in range(1, len(S)):
    if S[i-1] != S[i]:
        ans = 'Yes'

print(ans)