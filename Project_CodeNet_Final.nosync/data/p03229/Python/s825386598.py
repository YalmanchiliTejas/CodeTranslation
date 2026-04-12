from collections import deque
N = int(input())
A = [int(input()) for _ in range(N)] 

A.sort()
q = deque(A)

#小さいの中心
B = [0] * N


center = N // 2
minimum = q.popleft()
B[center] = minimum
left = center - 1
right = center + 1
cnt = 0
while q:
    if cnt % 4 == 0:
        num = q.pop()
        B[left] = num
        left -= 1
    elif cnt % 4 == 1:
        num = q.pop()
        B[right] = num
        right += 1
    elif cnt % 4 == 2:
        num = q.popleft()
        B[left] = num
        left -= 1
    elif cnt % 4 == 3:
        num = q.popleft()
        B[right] = num
        right += 1
    
    cnt += 1

ans_b = 0
for a,b in zip(B, B[1:]):
    ans_b += abs(a-b)

# 大きいの中心
q = deque(A)

B = [0] * N

center = N // 2
maximum = q.pop()
B[center] = maximum

left = center - 1
right = center + 1
cnt = 0
while q:
    if cnt % 4 == 2:
        num = q.pop()
        B[left] = num
        left -= 1
    elif cnt % 4 == 3:
        num = q.pop()
        B[right] = num
        right += 1
    elif cnt % 4 == 0:
        num = q.popleft()
        B[left] = num
        left -= 1
    elif cnt % 4 == 1:
        num = q.popleft()
        B[right] = num
        right += 1
    
    cnt += 1
#print("--", B, center)

ans_c = 0
for a,b in zip(B, B[1:]):
    ans_c += abs(a-b)




print(max(ans_b, ans_c))