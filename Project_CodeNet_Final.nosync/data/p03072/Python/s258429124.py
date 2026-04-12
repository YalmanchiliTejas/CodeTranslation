N = int(input())
h = list(map(int,input().split()))
pre_h = 0
c = 0
for r in h:
    if r >= pre_h:
        c+= 1
        pre_h = r
print(c)