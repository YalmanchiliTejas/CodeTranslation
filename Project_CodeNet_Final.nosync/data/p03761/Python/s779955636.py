from collections import Counter
n=int(input())
s=[Counter(input()) for i in range(n)]

A='abcdefghijklmnopqrstuvwxyz'
dic={i:0 for i in A}
for alpha in A:
    cnt=10**9
    for dic2 in s:
        if alpha in dic2:
            cnt=min(cnt,dic2[alpha])
        else:
            cnt=0
            break
    dic[alpha]=cnt

ans=''.join([i*dic[i] for i in A])
print(ans)