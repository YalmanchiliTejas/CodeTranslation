from collections import deque
N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()
d = deque(A)

#print(d)

# ans1[0] < ans1[1] > ans1[2] という大小関係になる配列を作成する
ans1 = []
for i in range(N):
    x = d.pop() if i % 2 == 0 else d.popleft()
    ans1.append(x)
x = ans1.pop()
ans1 = [x] + ans1

# ans2[0] > ans2[1] < ans2[2] という大小関係になる配列を作成する
ans2 = []
d = deque(A)
for i in range(N):
    x = d.popleft() if i % 2 == 0 else d.pop()
    ans2.append(x)
x = ans2.pop()
ans2 = [x] + ans2


def amount(array):
    ret = 0
    for i in range(N-1):
        ret += abs(array[i+1]-array[i])
    return ret

#print(ans)
print(max(amount(ans1), amount(ans2)))
