import math

#n=list(map(int,input().split()))
#x=int(input())
n=int(input())
s=input()
k=int(input())
s2=""
ch=s[k-1]
for a in range(len(s)):
    if ch==s[a]:
        s2+=s[a]
    else:
        s2+="*"
print(s2)