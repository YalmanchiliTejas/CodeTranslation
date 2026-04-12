n=int(input())
s=input()
k=int(input())
t=s[k-1]
c=''
for i in range(0,n):
    if s[i] != t:
        c += '*'
    else: c += s[i]

print(c)