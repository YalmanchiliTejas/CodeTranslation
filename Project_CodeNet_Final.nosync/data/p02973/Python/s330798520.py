from bisect import bisect, bisect_left, bisect_right,insort_right
n=int(input())
a=[int(input()) for i in range(n)]
c=[-1]*n
for i in a:
    c[bisect_left(c,i)-1]=i
print(n-bisect_right(c,-1))