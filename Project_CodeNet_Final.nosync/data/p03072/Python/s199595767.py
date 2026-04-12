nn = int(input())
hh = list(map(int, input().split()))
aa = 0

for ii in range(nn):
    mm = max(hh[:ii+1])
    if mm == hh[ii]:
        aa += 1
    
print(aa)