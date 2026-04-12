n = int(input())
lst = [int(input()) for _ in range(n)]
lst.sort()
if n%2==0:
    lower = lst[:n//2]
    upper = lst[n//2:]
    x = 2*sum(upper) - upper[0]
    y = 2*sum(lower) - lower[-1]
    print(x-y)
else:
    lower = lst[:n//2]
    upper = lst[n//2+1:]
    mid = lst[n//2]
    x = 2*sum(upper) - 2*sum(lower) - mid + lower[-1]
    y = 2*sum(upper) - 2*sum(lower) + mid - upper[0]
    print(max(x,y))