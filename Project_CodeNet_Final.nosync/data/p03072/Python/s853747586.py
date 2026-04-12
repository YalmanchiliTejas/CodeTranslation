_n = int(input())
_h = list(map(int, input().split()))
h_max = 0
c=0
for n in range(_n):
    if h_max<=_h[n]:
        c+=1
        h_max=_h[n]
print(c)
