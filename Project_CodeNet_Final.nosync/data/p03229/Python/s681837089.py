n = int(input())

A = []
for i in range(n):
    A.append(int(input()))
A.sort()
# print(A)

ans = 0
end = [A[0], A[-1]]
ans += abs(A[-1] - A[0])
A = A[1:-1]
s = 0
L = -1
for _ in range(n - 2):
    # print(ans, A, end)
    sl = [A[s], A[L]]
    # print(sl)

    tmp_l = []
    tmp_l.append(abs(end[0] - sl[0]))
    tmp_l.append(abs(end[1] - sl[0]))
    tmp_l.append(abs(end[0] - sl[1]))
    tmp_l.append(abs(end[1] - sl[1]))

    tmp = max(tmp_l)
    index = tmp_l.index(tmp)
    ans += tmp

    # print(index, tmp_l[index])
    if index % 2 == 0:
        end[0] = sl[index == 2]

    else:
        end[1] = sl[index == 3]

    if index < 2:
        s += 1
    else:
        L -= 1

print(ans)