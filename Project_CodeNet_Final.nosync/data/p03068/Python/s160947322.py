N = int(input())
S = input()
K = int(input()) - 1

key = S[K]
S_list = list(S)
for i in range(N):
    if S_list[i] != key:
        S_list[i] = "*"

ans = ""
for i in S_list:
    ans += i
print(ans)
