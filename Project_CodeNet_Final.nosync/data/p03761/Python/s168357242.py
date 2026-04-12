n=int(input())
s=input()
freq=[0]*26
for i in s:
    freq[ord(i)-ord('a')]+=1
for i in range(n-1):
    s=input()
    f=[0]*26
    for j in s:
        f[ord(j)-ord('a')]+=1
    for j in range(26):
        freq[j]=min(freq[j],f[j])
ans=''
for i in range(26):
    if freq[i]:
        while freq[i]>0:
            ans+=chr(i+ord('a'))
            freq[i]-=1
print(ans)
