n = int(input())
s = [input()for _ in range(n)]
alp = [chr(ord('a')+i)for i in range(26)]
cnt = [10**9]*26
for i in range(26):
    for x in s:
        cnt[i] = min(cnt[i],x.count(alp[i]))

ans = ""
for i in range(26):
    ans += alp[i]*cnt[i]
print(ans)   
    