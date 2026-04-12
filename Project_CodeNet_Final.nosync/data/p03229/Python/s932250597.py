from collections import deque

N = int(input())
A_list = sorted([int(input()) for _ in range(N)])

if N == 2:
    print(abs(A_list[0] - A_list[1]))
    exit()

if N == 3:
    a0,a1,a2 = A_list
    print(max(abs(a0-a1) + abs(a1-a2),abs(a1-a2) + abs(a2-a0) ,abs(a0-a2) + abs(a0-a1)))
    exit()
    
q = deque(A_list)
res_q = deque([q.popleft(), q.pop()])
l = res_q[0]
r = res_q[-1]

v1 = v2 =0

v1 = q.popleft()
v2 = q.pop()
res = abs(l-r)
for _ in range(2,N-2):
    diff_l1 = abs(l-v1)
    diff_l2 = abs(l-v2)
    diff_r1 = abs(r-v1)
    diff_r2 = abs(r-v2)
    max_diff = max(diff_l1,diff_l2, diff_r1, diff_r2)
    
    res += max_diff
    if diff_l1 == max_diff:
        l = v1
        v1 = q.popleft()
    elif diff_l2 == max_diff:
        l = v2
        v2 = q.pop()
    elif diff_r1 == max_diff:
        r = v1
        v1 = q.popleft()
    else:
        r = v2
        v2 = q.pop()

# あまった2つの処理
diff_list = [abs(l-v1) + abs(v1-v2),
            abs(l-v1) + abs(r-v2),
            abs(l-v2) + abs(v1-v2),
            abs(l-v2) + abs(r-v1),
            abs(r-v1) + abs(l-v2),
            abs(r-v1) + abs(v1-v2),
            abs(r-v2) + abs(l-v1),
            abs(r-v2) + abs(v1-v2)]
res += max(diff_list)

print(res)