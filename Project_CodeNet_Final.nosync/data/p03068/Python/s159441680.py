n=int(input())
s=input()
k=int(input())

mark=s[k-1]

for i in range(n):
    if s[i]!=mark:
        s=s.replace(s[i],"*")
print(s)