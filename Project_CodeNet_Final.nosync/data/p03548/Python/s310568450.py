x,y,z = map(int,input().split())
hi = 100000
lo = 0
mid = (hi+lo)//2
while hi-lo > 1:
    mid = (hi+lo)//2
    if mid*y + (mid+1)*z <= x:
        lo = mid
    else:
        hi = mid
print(lo)
