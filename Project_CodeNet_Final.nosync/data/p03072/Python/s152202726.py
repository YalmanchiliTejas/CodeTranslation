n = int(input())
h = list(map(int,input().split()))
ls = []
d = 1
for i in range(n-1):
    ls.append(h[i])
    c = 0
    for j in range(len(ls)):
        if ls[j] <= h[i+1]:
            c += 1
        if c == len(ls):
            d += 1
        
print(d)