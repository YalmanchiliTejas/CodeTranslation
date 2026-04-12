n = int(input())
s = [input()for i in range(n)]
a = "abcdefghijklmnopqrstuvwxyz"
cnt = []
for i in a:
    mi = 50
    for j in s:
        mi = min(mi,j.count(i))
    cnt.append(mi)
ans =""
for i in  range(26):
    ans +=a[i]*cnt[i]
print(ans)