def comb(n,k):
    if k==0:
        return 1
    elif k==1:
        return n
    elif k==2:
        return n*(n-1)/2

n = input()
k = int(input())
ans=0
for dgt in range(1,len(n)):
    if dgt<len(n):
        ans+=9**k*comb(dgt-1,k-1)
dgt=len(n)
cnt=0
for i in range(len(n)):
    if n[i] != '0' and cnt<k:
        cnt+=1
        ans+=(int(n[i])-1)*9**(k-cnt)*comb(dgt-i-1, k-cnt)
        if i:
            ans+=9**(k-cnt+1)*comb(dgt-i-1, k-cnt+1)

if cnt==k:
    ans+=1
print(int(ans))



