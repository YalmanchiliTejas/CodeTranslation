def getN():
    return int(input())
def getNM():
    return map(int, input().split())
def getList():
    return list(map(int, input().split()))

ans = 0
N, K = getNM()
for i in range(N):
    b = i + 1
    if b > K:
        set = N // b
        ans += set*(b-K)
        rem = N % b
        if K == 0:
            ans -=1
        ans += max(rem-K+1,0)
print(ans)
