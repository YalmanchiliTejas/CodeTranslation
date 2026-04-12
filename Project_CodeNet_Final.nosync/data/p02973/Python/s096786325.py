N = int(input())

A = []
for _ in range(N):
    a = int(input())
    A.append(a)
    
nums = A[:]
colors = [float('inf')] * N

from bisect import bisect_left, bisect_right, insort_right
ans = 0
for n in nums:
    idx = bisect_right(colors, -n)
    colors[idx] = -n
    #print(ans)
    if idx > ans:
        ans = idx
    #print(idx, colors)
            
print(ans+1)

        