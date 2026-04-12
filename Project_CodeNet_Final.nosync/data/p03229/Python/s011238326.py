import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n = int(input())
a = [None]*n
for i in range(n):
    a[i] = int(input())
    
a.sort()
b = [None]*n
if n%2==0:
    b[0] = a[n//2-1]
    b[-1] = a[n//2]
    l1 = a[:n//2-1]
    l2 = a[n//2+1:][::-1]
    for i in range(len(l1)):
        b[2*i+1] = l2[i]
        b[2*i+2] = l1[i]
    ans = sum(abs(b[i]-b[i+1]) for i in range(n-1))
else:
    ind = n//2+1
    b[0] = a[ind]
    b[-1] = a[n//2]
    l1 = a[:n//2]
    l2 = a[ind:][::-1]
    b[1] = l1[0]
    for i in range(len(l1)-1):
        b[2*i+2] = l2[i]
        b[2*i+3] = l1[i+1]
    ans1 = sum(abs(b[i]-b[i+1]) for i in range(n-1))
    
    ind = n//2-1
    b[0] = a[n//2]
    b[-1] = a[ind]
    l1 = a[:ind]
    l2 = a[n//2+1:]
    b[1] = l2[0]
    for i in range(len(l2)-1):
        b[2*i+2] = l1[i]
        b[2*i+3] = l2[i+1]
    ans2 = sum(abs(b[i]-b[i+1]) for i in range(n-1))
    ans = max(ans1, ans2)
print(ans)