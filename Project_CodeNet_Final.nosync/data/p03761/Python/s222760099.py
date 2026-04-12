n=int(input())
d=[dict() for _ in range(n)]
for i in range(n):
    for c in input():
        if c not in d[i]:
            d[i][c]=1
        else:
            d[i][c]+=1
ans=""
for i in range(26):
    mini=10**18
    for j in range(n):
        if chr(97+i) not in d[j]:
            mini=0
        else:
            mini=min(mini,d[j][chr(97+i)])
    ans+=mini*chr(97+i)
print(ans)