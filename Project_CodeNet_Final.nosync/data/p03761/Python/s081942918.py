n=int(input())
s=input()
sd={}
for si in s:
    if si in sd.keys():
        sd[si]+=1
    else:
        sd[si]=1
for i in range(n-1):
    st=input()
    for k in sd:
        if st.count(k)<sd[k]:
            sd[k]=st.count(k)
ans=''
for k in sd:
    ans+=k*sd[k]
print(''.join(sorted(ans)))