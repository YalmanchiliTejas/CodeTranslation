n=int(input())
s=list(str(input()))
k=int(input())
for i in range(len(s)):
    if s[i]!=s[k-1]:
        s[i] = "*"
print("".join(s))
