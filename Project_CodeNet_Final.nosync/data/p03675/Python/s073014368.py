import collections

b = collections.deque()
n = int(input())
As = list(map(int, input().split()))
for i, a in enumerate(As):
    if i & 1:
        b.append(a)
    else:
        b.appendleft(a)
if n % 2 == 0:
    b.reverse()
print(*b)
