n=int(input())

for k in range(n):
    s=input()
    tmp=[0]*26
    for i in range(len(s)):
        tmp[ord(s[i])-ord("a")]+=1

    if k==0: ans=tmp 
    else:
        for i in range(26):
            ans[i]=min(ans[i],tmp[i])

p=ord("a")
for i in range(26):
    for _ in range(ans[i]):
        print(chr(p+i),end="")