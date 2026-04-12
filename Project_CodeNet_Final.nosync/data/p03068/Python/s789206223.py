n=int(input())
s=input()
k=int(input())
a=''

for i in range(n):
    if s[i]==s[k-1]:
        a+=s[i]
    else:
        a+='*'
print(a)
