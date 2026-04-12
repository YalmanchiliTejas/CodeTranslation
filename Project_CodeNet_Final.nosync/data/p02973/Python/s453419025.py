import bisect
N = int(input())
A = [-int(input()) for _ in range(N)]
tmp = [A[0]]
for i in A[1:N]:
    index = bisect.bisect(tmp, i)
    if index == len(tmp):
        tmp.append(i)
    else:
        tmp[index] = i

print(len(tmp))
