n=int(input())
s=input()
k=int(input())
b=s[k-1]
ss=""
for a in s:
    if a!=b:
        ss+="*"
    else:
        ss+=a
print(ss)