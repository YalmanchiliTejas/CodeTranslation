n=int(raw_input())
a=map(int,raw_input().split())
ansr=[]
ansl=[]
if n%2==0:
    for i in xrange(0, n, 2):
        ansr.append(a[i])
    for i in xrange(1, n, 2):
        ansl.append(a[i])
else:
    for i in xrange(0, n, 2):
        ansl.append(a[i])
    for i in xrange(1, n, 2):
        ansr.append(a[i])
ansl.reverse()
print " ".join(map(str,ansl)) +" "+ " ".join(map(str, ansr))
