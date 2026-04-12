from collections import Counter

n=int(input())
count=Counter(input())
for i in range(n-1):
    t_count=Counter(input())
    for c_k in count.keys():
        if c_k in t_count.keys():
            count[c_k]=min(count[c_k],t_count[c_k])
        else:
            count[c_k]=0
s=''
for c_k in sorted(count.keys()):
    s+=c_k*count[c_k]
print(s)