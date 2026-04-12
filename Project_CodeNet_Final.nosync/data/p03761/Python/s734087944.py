n=int(input())
az=[float("inf")]*26
for i in range(n):
    s=input()
    for j in range(26):
        az[j]=min(az[j],s.count(chr(j+97)))
ans=""
for i in range(26):
    ans+=chr(i+97)*az[i]
print(ans)