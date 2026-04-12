n=int(input())
s=input()
k=int(input())

a=s[k-1]
t=""

for i in range(n):
    if(s[i]==a):
        t+=a
    else:
        t+="*"

print(t)