N  = int(input())
S = input()
K = int(input())
ans = ""
str1 = S[K-1]
for i in range(N):
    if S[i] == str1:
        ans = ans + str1
    else:
        ans = ans + "*"
print(ans)