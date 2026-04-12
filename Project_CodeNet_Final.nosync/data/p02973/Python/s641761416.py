def reverse_bisect(a, x, lo=0, hi=None):
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo+hi)//2
        if x > a[mid]: hi = mid
        else: lo = mid+1
    return lo

N = int(input())
color_list = []
color_len = 0
for i in range(N):
    a = int(input())
    index = reverse_bisect(color_list, a, 0, color_len)
    if(index == color_len):
        color_list.append(a)
        color_len += 1
    else:
        color_list[index] = a
print(color_len)
