n, x, m = map(int, input().split())

s = set()
idx = {i: -1 for i in range(m)}
cumsum = [0]
val = x
idx[val] = 0
for i in range(n):
    cumsum.append(cumsum[-1] + val)
    val = pow(val, 2, m)
    if idx[val] != -1:
        break
    idx[val] = i + 1

if len(cumsum) > n:
    print(cumsum[n])
else:
    loop_len = i + 1 - idx[val]
    print((cumsum[i+1]-cumsum[idx[val]]) * ((n-idx[val])//loop_len) + cumsum[idx[val]+(n-idx[val])%loop_len])
