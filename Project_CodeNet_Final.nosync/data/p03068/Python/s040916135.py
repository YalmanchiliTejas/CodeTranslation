N = int(input())
S = str(input())
K = int(input())
target_char = S[K-1]
ans = []
for i in range(N):
    if S[i] != target_char:
        ans.append("*")
    else:
        ans.append(target_char)
ans2 = ""
for i in range(N):
    ans2 += ans[i]
print(ans2)