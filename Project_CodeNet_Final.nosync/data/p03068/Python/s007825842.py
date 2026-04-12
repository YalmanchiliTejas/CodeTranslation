N = int(input())
S = input()
K = int(input())
 
ans = ""
for c in S:
    if S[K-1] != c:
        ans += '*'
    else:
        ans += c
 
print(ans)