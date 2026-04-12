n = int(input())
s = []
for _ in range(n):
    s.append(input())
s.sort(key=len)
moji = set(s[0])
ans=[]
for cha in moji:
    mn=10**9
    for st in s:
        cnt = st.count(cha)
        if cnt < mn:
            mn = cnt
    for i in range(mn):
        ans.append(cha)
ans.sort()
print(*ans,sep="")