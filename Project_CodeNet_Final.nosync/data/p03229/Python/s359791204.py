from sys import stdin
N = int(stdin.readline().rstrip())
A = []
for i in range(N):
    A.append(int(input()))

A.sort()


if N % 2 != 0:
    ans1 = 0
    tmp = [-1,-1] + [2]*((N-1)//2) + [-2]*((N-2)//2)
    for i,j in zip(sorted(tmp),A):
        ans1 += (i*j)
    
    ans2 = 0
    tmp = [1,1] + [2]*((N-2)//2) + [-2]*((N-1)//2)
    for i,j in zip(sorted(tmp),A):
        ans2 += (i*j)
    print(max(ans1,ans2))
else:
    ans = 0
    tmp = [-1,1] + [2]*((N-2)//2) + [-2]*((N-2)//2)
    for i,j in zip(sorted(tmp),A):
        ans += (i*j)
    print(ans)