n=int(input())
a=[input()for i in range(n)]
ans=""
for i in range(97,97+26):
    cnt=float("inf")
    for j in range(n):
        ven=a[j].count(chr(i))
        cnt=min(cnt,ven)
    ans+=chr(i)*cnt
print(ans)
