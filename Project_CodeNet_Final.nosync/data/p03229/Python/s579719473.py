from collections import deque
N = int(input())
A = list(int(input()) for _ in range(N))

ans = 0
d = deque(sorted(A))
while len(d) > 3:
    ans += 2*(deque.pop(d)-deque.popleft(d))
if len(d) == 2:
    ans += deque.pop(d)-deque.popleft(d)
else:
    a, b, c = d
    ans += max(b+c-2*a, -a-b+2*c) 
    
print(ans)