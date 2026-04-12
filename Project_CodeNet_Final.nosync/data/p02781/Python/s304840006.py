n = int(input())
k = int(input())

d_sum = [[0,0,0] for i in range(101)]
pre = [0,0,0]
for i in range(1,101):
    pre[0] += 9
    pre[1] += 81*(i-1)
    pre[2] += (9**3)*(i-1)*(i-2)//2
    d_sum[i][0] = pre[0]
    d_sum[i][1] = pre[1]
    d_sum[i][2] = pre[2]

s = str(n)

ans = d_sum[len(s)-1][k-1]

nonzero = 0
for ind, i in enumerate(s):
    if int(i)==0:
        continue
    digit = len(s)-ind-1
    if ind==0:
        nonzero += 1
        if nonzero==k:
            ans += int(i)
            break
        ans += (int(i)-1)*d_sum[digit][k-nonzero-1]
    else:
        ans += d_sum[digit][k-nonzero-1]
        nonzero += 1
        if nonzero==k:
            ans += int(i)
            break
        ans += (int(i)-1)*d_sum[digit][k-nonzero-1]

print(ans)