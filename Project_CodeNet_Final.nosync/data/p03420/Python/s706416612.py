from sys import stdin
n,k = map(int,stdin.readline().rstrip().split())
point = 0
#n=p*b+r
for b in range(1,n+1):
    p = n//b
    r = n%b
    point += p*max(0,b-k)
    point += max(0,r-k+1)
if k == 0:
    point -= n
print(point)