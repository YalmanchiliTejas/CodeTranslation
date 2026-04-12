n=int(input())
s=input()
k=int(input())
a=""
for i in s:
    if i==s[k-1]:
        a+=s[k-1]
    else:a+="*"    
print(a) 