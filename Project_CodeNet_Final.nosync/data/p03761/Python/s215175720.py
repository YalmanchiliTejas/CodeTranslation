n=int(input())
s=[""]*n
for i in range(n):
    s[i]=input()
ss=list(set(s[0]))
ss.sort()

stmin=[50]*len(ss)
for si in s:
    for ii in range(len(ss)):
        stmin[ii]=min(stmin[ii],si.count(ss[ii]))

t=""
for i in range(len(ss)):
    t=t+ss[i]*stmin[i]
print(t)
