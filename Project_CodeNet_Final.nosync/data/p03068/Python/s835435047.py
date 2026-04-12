N  = int (input())
S = input()
K = int(input())
K = K-1
ans = ""
c = S[K]

for s in S:
    if s == c:
            ans+= s
    else:
            ans+="*"
print(ans)
