N = int(input())
S = input()
K = int(input())
target = S[K - 1]
ans = ''
for char in S:
    if char != target:
        ans += '*'
    else:
        ans += target
print(ans)
