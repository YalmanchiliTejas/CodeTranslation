# -*- coding: utf-8 -*-
N = int(input())
A = []
for _ in range(N):
    A.append(int(input()))

As = sorted(A)
Ar = sorted(A)
Ar.reverse()


cent = (N+1)//2 - 1

ans = [0 for _ in range(N)]
for i in range(cent+1):
    if i == 0:
        ans[cent] = As[0]
    elif i % 2 == 1:
        ans[cent+i] = Ar[i-1]
        ans[cent-i] = Ar[i]
    else:
        ans[cent+i] = As[i-1]
        ans[cent-i] = As[i]

if N % 2 == 0:
    if cent % 2 == 0:
        ans[-1] = Ar[cent]
    else:
        ans[-1] = As[cent]

diff = 0
for i in range(N-1):
    diff += abs(ans[i] - ans[i+1])

# print(As)
# print(Ar)
# print(ans)
# print(diff)

ans = [0 for _ in range(N)]
for i in range(cent+1):
    if i == 0:
        ans[cent] = Ar[0]
    elif i % 2 == 1:
        ans[cent+i] = As[i-1]
        ans[cent-i] = As[i]
    else:
        ans[cent+i] = Ar[i-1]
        ans[cent-i] = Ar[i]

if N % 2 == 0:
    if cent % 2 == 0:
        ans[-1] = As[cent]
    else:
        ans[-1] = Ar[cent]

diff2 = 0
for i in range(N-1):
    diff2 += abs(ans[i] - ans[i+1])

# print(ans)
# print(diff2)

print(max([diff,diff2]))
