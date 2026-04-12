n=int(input())
s=[]
for i in range(n):
    S = str(input())
    s.append(S)
al=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
cnt=[51]*26
for i in range(26):
    for j in range(n):
        cnt[i]=min(cnt[i],s[j].count(al[i]))
ans=""
for i in range(26):
    ans+=al[i]*cnt[i]
print(ans)

