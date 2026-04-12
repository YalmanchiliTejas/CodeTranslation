from collections import defaultdict

n = int(input())
s = []
t = []
a = defaultdict(int)
for i in range(n):
    d = defaultdict(int)
    st = list(input())
    st.sort()
    for j in range(len(st)):
        d[st[j]]+=1    
    if i==0:
        t = set(st)
        for j in t:
            a[j] = d[j]
    else:
        u = set(st)
        t = t & u 
        for j in t:
            a[j] = min(a[j],d[j])
ans = ""
t = list(t)
t.sort()
for i in t:
    for j in range(a[i]):
        ans = ans + i
print(ans)