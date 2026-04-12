#import bisect
def desc_bin(a, x, lo=0, hi=None):
    """Insert item x in list a, and keep it reverse-sorted assuming a
    is reverse-sorted.

    If x is already in a, insert it to the right of the rightmost x.

    Optional args lo (default 0) and hi (default len(a)) bound the
    slice of a to be searched.
    """
    if lo < 0:
        raise ValueError('lo must be non-negative')
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo+hi)//2
        if x > a[mid]: hi = mid
        else: lo = mid+1
    return lo
N=int(input())
ans=[]
for _ in range(N):
    num=int(input())
    
    index=desc_bin(ans,num)
    if index==len(ans):
        ans.append(num)
    else:
        ans[index]=num
    #print(ans)
print(len(ans))