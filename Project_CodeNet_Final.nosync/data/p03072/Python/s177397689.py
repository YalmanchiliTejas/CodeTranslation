from sys import stdin
N=int(stdin.readline().rstrip())
data=[int(x) for x in stdin.readline().rstrip().split()]
ans=0
hi=0
for i in data:
    if i >= hi:
        ans+=1
        hi=i
print(ans)