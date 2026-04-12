n=int(input())
s=input()
l=int(input())
x=s[l-1]
for i in range(n):
    if s[i]!=x:
        s=s.replace(s[i],"*")
print(s)