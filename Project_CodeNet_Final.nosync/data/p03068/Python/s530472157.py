n=int(input())
s=input()
k=int(input())

for i in range(len(s)):
    if s[i]!=s[k-1]:
        s=s.replace(s[i],'*')

print(s)