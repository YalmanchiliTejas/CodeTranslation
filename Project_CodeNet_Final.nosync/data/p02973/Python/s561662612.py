from collections import deque

def replace(l, a, max_idx, min_idx):
    if max_idx == min_idx:
        l[max_idx] = a
        return

    center = (max_idx + min_idx)//2
    if l[center] >= a:
        return replace(l, a, max_idx, center+1)
    else:
        return replace(l, a, center, min_idx)


N = int(input())
A = [int(input()) for _ in range(N)]


l = []

for a in A:
    if len(l) == 0:
        l.append(a)
    elif l[-1] >= a:
        l.append(a)
    else:
        replace(l, a, len(l)-1, 0)

print(len(l))
