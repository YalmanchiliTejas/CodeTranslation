N = int(input())
S = input()
K = int(input())
ans = []
for s in S:
    if S[K-1] != s:
        ans.append("*")
    else:
        ans.append(s)
print("".join(ans))
