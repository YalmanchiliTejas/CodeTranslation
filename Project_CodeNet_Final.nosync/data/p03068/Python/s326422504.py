n=int(input())
s=input()
k=int(input())
for i in range(n):
    if s[k-1] != s[i]:
        s = s.replace(s[i],"*")
print(s)