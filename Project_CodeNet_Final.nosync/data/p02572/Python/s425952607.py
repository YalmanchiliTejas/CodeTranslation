n = int(input())
array = list(map(int, input().split()))
sum = sum(array)
answer = 0
from collections import deque
d = deque(array)
for i in range(n):
    a = d.popleft()
    sum -= a
    answer += a*sum
    answer %= 10**9 + 7
print(answer)