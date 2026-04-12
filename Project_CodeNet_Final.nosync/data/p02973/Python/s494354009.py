import bisect
n = int(input())
a = [int(input()) for i in range(n)]
answer = []

for i in range(n):
    if i == 0:
        answer.append(-a[i])
    elif -answer[-1] >= a[i]:
        answer.append(-a[i])
    else:
        a_index = bisect.bisect_right(answer, -a[i])
        answer[a_index] = -a[i]

print(len(answer))
