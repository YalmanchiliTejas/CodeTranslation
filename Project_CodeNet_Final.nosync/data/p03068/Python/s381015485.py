N = int(input())
S = input()
K = int(input())

SS = S[K - 1]
ans = ""

for i in S:
    if i == SS:
        ans += i
    else:
        ans += "*"
        
print(ans)