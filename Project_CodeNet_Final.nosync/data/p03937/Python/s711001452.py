# coding: utf-8
# Here your code !

H,W=map(int,raw_input().split())
c=0
for _ in xrange(H):
    s=raw_input()
    for i in xrange(W):
        if s[i]=="#": c+=1
if H+W-1==c: print "Possible"
else: print "Impossible"