N = int(input())
A = [int(input()) for i in range(N)]

A.sort()

l,r = A[0],A[0]
cnt = 1
l_cnt = cnt
r_cnt = 1
ans1 = 0
while True:
    ans1 += abs(l-A[-r_cnt])
    l = A[-r_cnt]
    cnt += 1
    r_cnt += 1
    if cnt == N:
        break

    ans1 += abs(r-A[-r_cnt])
    r = A[-r_cnt]
    cnt += 1
    r_cnt += 1    
    if cnt == N:
        break

    ans1 += abs(l-A[l_cnt])
    l = A[l_cnt]
    cnt += 1
    l_cnt += 1
    if cnt == N:
        break

    ans1 += abs(r-A[l_cnt])
    r = A[l_cnt]
    cnt += 1
    l_cnt += 1
    if cnt == N:
        break

l,r = A[-1],A[-1]
cnt = 1
l_cnt = 0
r_cnt = 2
ans2 = 0
while True:
    ans2 += abs(l-A[l_cnt])
    l = A[l_cnt]
    cnt += 1
    l_cnt += 1
    if cnt == N:
        break

    ans2 += abs(r-A[l_cnt])
    r = A[l_cnt]
    cnt += 1
    l_cnt += 1
    if cnt == N:
        break

    ans2 += abs(l-A[-r_cnt])
    l = A[-r_cnt]
    cnt += 1
    r_cnt += 1
    if cnt == N:
        break

    ans2 += abs(r-A[-r_cnt])
    r = A[-r_cnt]
    cnt += 1
    r_cnt += 1    
    if cnt == N:
        break

print(max(ans1,ans2))