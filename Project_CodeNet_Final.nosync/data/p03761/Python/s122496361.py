import collections
n = int(input())
ans = ''

tmp1 = input()
cnt = collections.Counter(tmp1)

for i in range(n-1):
    tmp2 = input()
    cnt2 = collections.Counter(tmp2)
    for k,v in cnt.items():
        if k in cnt2:
            if v > cnt2[k]:
                cnt[k] = cnt2[k]
        else:
            cnt[k]=0

cnt = sorted(cnt.items())
            
for i in range(len(cnt)):
    if cnt[i][1] > 0:
        ans += cnt[i][0] * cnt[i][1]
        
print(ans)