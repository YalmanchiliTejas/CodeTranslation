N =int(input())
Hlist = list(map(int, input().split()))
maxH = 0
v = 0
for h in Hlist :
    if maxH <= h :
        v += 1
        maxH = h
print(v)