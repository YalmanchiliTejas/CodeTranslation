n=int(input())
s=[input()for i in range(n)]
ans=""
for i in range(97,97+26):
    small=float("inf")
    for j in range(n):
        cnt=0
        for k in range(len(s[j])):
            if s[j][k]==chr(i):
                cnt+=1
        small=min(small,cnt)
    for l in range(small):
        ans+=chr(i)
print(ans)

