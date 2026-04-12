import bisect

N = int(input())
a = [int(input()) for _ in range(N)]
b = [a[-1]]
for i in range(2, N+1):
    x = a[-i]
    index = bisect.bisect_right(b, x)
    if index == len(b):
        b.append(x)
    else:
        b[index] = x
print(len(b))    
    