import sys
def input(): return sys.stdin.readline().rstrip()

N, X, M = map(int, input().split())

numlist = [-1] * M

num = X
ans = num
roop_start = -1
for i in range(N-1):
    new_num = (num * num) % M
    if numlist[num] == -1:
        numlist[num] = new_num
        ans += new_num
        num = new_num
    else:
        roop_start = num
        break

num = roop_start
if roop_start == -1:
    print(ans)
else:
    roop_sum = [num]
    for i in range(N-1):
        new_num = numlist[num]
        numlist[num] = -1
        if numlist[new_num] == -1:
            break
        else:
            roop_sum.append(roop_sum[-1] + new_num)
            num = new_num
        
    if numlist[X] != -1:
        count = 0
        ans = 0
        for i in range(M):
            if numlist[i] != -1:
                ans += i
                count += 1
        N -= count
    else:
        ans = 0

    size = len(roop_sum)
    div = N // size
    rest = N % size
    ans += div * roop_sum[-1]
    if rest != 0:
        ans += roop_sum[rest-1]
    print(ans)