s=input()
ans=int()
for i in range(len(s)):
    if (s[i-1]=='A')&(s[i]=='C'):
        ans+=1
print('YNeos'[ans==0::2])   