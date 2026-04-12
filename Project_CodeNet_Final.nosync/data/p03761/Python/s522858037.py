from collections import Counter

n=int(input())
count=Counter(input())
for i in range(n-1):
    count&=Counter(input())
s=''
for c_k in sorted(count.keys()):
    s+=c_k*count[c_k]
print(s)