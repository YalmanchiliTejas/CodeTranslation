from collections import deque
N = int(input())
A = list(map(int, input().split()))
#N=3
#A=[1,2,3]
q=deque(A)
#print(q)
ans=0
sums=sum(q)
#print(sums)
for i in range(N-1):
    qwe=q.popleft()
    ans+=qwe *(sums-qwe)
    sums-=qwe
print(ans%(10**9+7))