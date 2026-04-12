from bisect import bisect
N = int(input())
A = [-int(input()) for i in range(N)]

mem = []
for a in A:
    i = bisect(mem, a)
    if i==len(mem):
        mem.append(a)
    else:
        mem[i] = a
print(len(mem))