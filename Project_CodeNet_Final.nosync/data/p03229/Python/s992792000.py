from collections import deque
n = int(input())

A = []
for _ in range(n):
    a = int(input())
    A.append(a)
A_ = deque()

l = 0
r = len(A)-1

A = sorted(A)

for _ in range(n):
    if len(A_) == 0:
        A_.append(A[r])
        r-=1
        continue

    todo = "ll"
    bestVal = abs(A[l]-A_[0])
    if(abs(A[l]-A_[-1]) > bestVal):
        bestVal = abs(A[l]-A_[-1])
        todo = "lr"
    if(abs(A[r]-A_[-1]) > bestVal):
        bestVal = abs(A[r]-A_[-1])
        todo = "rr"
    if(abs(A[r]-A_[0]) > bestVal):
        bestVal = abs(A[r]-A_[0])
        todo = "rl"

    if todo == "ll":
        A_.appendleft(A[l])
        l+=1
    if todo == "lr":
        A_.append(A[l])
        l+=1
    if todo == "rr":
        A_.append(A[r])
        r-=1
    if todo == "rl":
        A_.appendleft(A[r])
        r-=1
ans = 0
for i in range(len(A_)-1):
    ans += abs(A_[i+1]-A_[i])
print(ans)
