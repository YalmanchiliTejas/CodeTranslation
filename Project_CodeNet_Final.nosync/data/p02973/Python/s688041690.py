n = int(input())
an = [0]*n
for i in range(0, n):
    an[i] = int(input())
dp = [-1] * n

len = 1
dp[0] = an[0]
for i in range(1,n):
    if dp[len-1] >= an[i]:
        dp[len] = an[i]
        len += 1
        continue
    
    idx = len // 2
    r = len-1
    l = 0
    while(True):
        if dp[idx] >= an[i]:
            if r == idx+1:
                dp[r] = an[i]
                break
            else:
                l = idx
                idx = idx + (r - idx) // 2
        else:
            if l == idx:
                dp[l] = an[i]
                break
            else:
                r = idx
                idx = l + (idx - l) // 2
    
print(len)
