N = int(input())
S = input()
K = int(input())
ans = ''
k = S[K-1]
for i in S:
    if i != k:
        ans += '*'
    else:
        ans += i
print(ans)