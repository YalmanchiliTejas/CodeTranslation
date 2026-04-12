n = int(input())
A = list(map(int,input().split()))
if n%2 == 0:
    dmax = 0
    ans = sum(A[::2])
    d = [0]*(n//2 + 1)
    for i in range(n//2):
        d[i+1] = d[i] + A[-2*i-1] - A[-2*i-2]
        dmax = max(dmax, d[i+1])
    print(ans + dmax)
else:
    d1 = [0]*(n//2 + 1)
    d1max = [0]*(n//2 + 1)
    d2 = [0]*(n//2 + 1)
    d2max = 0
    ans = sum(A[:-2:2])
    for i in range(n//2):
      d1[i+1] = d1[i] + A[-2*i-1] - A[-2*i-2]
      d1max[i+1] = max(d1max[i], d1[i+1])
      d2[i+1] = d2[i] + A[-2*i-2] - A[-2*i-3]
      d2max = max(d2max, d2[i+1] + d1max[i+1])
    print(ans + d2max)
