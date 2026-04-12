N = int(input())
S = input()
K = int(input())
save = S[K-1]
ans = "*"*N
for x in range(N):
    if x == 0 :
        if S[x] == save:
            ans =save + ans[x+1:]
        continue
    if S[x] == save:
        ans = ans[:x] + save + ans[x+1:]
print(ans)