n = int(input())
k = int(input())
m = len(list(str(n)))
n0 = list(str(n))
for i in range(m):
    n0[i] = int(n0[i])
ans = 0
comb = 1
if k < m:
    for j in range(k):
        comb *= (m-1-j)
        comb //= (j+1)
    ans += comb*(9**k)
#print(ans,k,m)
if k == 1:
    ans += n0[0]
elif k == 2:
    if m >= 2:
        ans += (n0[0]-1)*9*(m-1)
        c = 1
        while n0[c] == 0 and c < m-1:
            c += 1
        if n0[c] > 0:
            ans += n0[c]
            ans += 9*(m-c-1)
    else:
        ans = 0
else:
    if m >= 3:
        ans += (n0[0]-1)*9*9*(m-1)*(m-2)//2
        c = 1
        while n0[c] == 0 and c <= m-2:
            c += 1
        if c < m-1:
            ans += (n0[c]-1)*9*(m-c-1)
            ans += 9*9*(m-c-1)*(m-c-2)//2
            c1 = c+1
            while n0[c1] == 0 and c1 < m-1:
                c1 += 1
            if n0[c1] > 0:
                ans += n0[c1]
                ans += 9*(m-c1-1)
    else:
        ans = 0
print(ans)