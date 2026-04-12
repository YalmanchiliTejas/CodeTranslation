ans=[0 for i in range(26)]
n=int(input())
s=input()
for j in range(len(s)):
    ans[ord(s[j])-97]+=1
if n>1:
    for i in range(n-1):
        tmp=[0 for i in range(26)]
        s=input()
        for j in range(len(s)):
            tt=ord(s[j])-97
            tmp[tt]+=1
        for k in range(26):
            if tmp[k]<ans[k]:
                ans[k]=tmp[k]
a=""
for i in range(26):
    a+=chr(i+97)*ans[i]
print(a)