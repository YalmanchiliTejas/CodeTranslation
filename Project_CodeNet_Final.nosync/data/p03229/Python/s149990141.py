import copy

N = int(input())
A = []
for i in range(N):
    x = int(input())
    A.append(x)
A.sort()
B = copy.copy(A)
ans1 = 0
ans2 = 0

for i in range(1,len(A)-1):
    if i%2 == 0:
        ans1 -= 2 * A.pop(0)
    else:
        ans1 += 2 * A.pop()

if N%2 == 1:
    ans1 = ans1 - A[0] - A[1]
else:
    ans1 = ans1 - min(A[0], A[1]) + max(A[0], A[1])
A = B

for i in range(1,len(A)-1):
    if i%2 == 0:
        ans2 += 2 * A.pop()
    else:
        ans2 -= 2 * A.pop(0)

if N%2  ==1:
    ans2 = ans2 + A[0] + A[1]
else:
    ans2 = ans2 + max(A[0], A[1]) - min(A[0], A[1])
    
print(max(ans1, ans2))
