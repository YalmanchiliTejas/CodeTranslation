#coding:utf-8
n = int(input())
S = [list(input()) for i in range(n)]
query = S.pop()
ans = ""
for q in query:
    ok = True
    for s in S:
        if (q not in s):
            ok = False
    if ok:
        ans += q
        for s in S:
            s.remove(q)
print ("".join(sorted(ans)))


