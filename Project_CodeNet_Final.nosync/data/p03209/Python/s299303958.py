N,X = map(int, input().split())
num, p = [1], [1]
index = 1
while N >= index:
    num.append(2*num[-1] + 3)
    p.append(2*p[-1] + 1)
    index +=1

def ans(n, x):
    if n == 0:
        return 1 if x > 0 else 0
    if x <= num[n-1]+1:
        return ans(n-1, x-1)
    else:
        return p[n-1] +1+ ans(n-1, x-2-num[n-1])

print(ans(N, X))