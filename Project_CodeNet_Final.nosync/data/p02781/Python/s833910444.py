n = list(map(int, list(input())))
k = int(input())
ln = len(n)

if ln < k:
    print(0)
    exit()

#comb(n,r) = nCr
def comb(n, r):
    m = 1
    for i in range(n-r+1, n+1):
        m *= i
    for i in range(1, r+1):
        m //= i
    return m

ans = 0

#ln-1桁以下を処理
if ln > k:
    ans += comb(ln-1, k) * (9 ** k)

#ln桁を処理
ans += comb(ln-1, k-1) * (9**(k-1)) * (n[0]-1)

if k == 1:
    ans += 1

elif k == 2:
    for i in range(1, ln):
        if n[i] != 0:
            ans += comb(ln-i-1, k-1) * (9**(k-1))
            ans += comb(ln-i-1, k-2) * (9**(k-2)) * (n[i]-1)
            ans += 1
            break

else:
    for i in range(1, ln):
        if n[i] != 0:
            ans += comb(ln-i-1, k-1) * (9**(k-1))
            ans += comb(ln-i-1, k-2) * (9**(k-2)) * (n[i]-1)
            for j in range(i+1, ln):
                if n[j] != 0:
                    ans += comb(ln-j-1, k-2) * (9**(k-2))
                    ans += comb(ln-j-1, k-3) * (9**(k-3)) * (n[j]-1)
                    ans += 1
                    break
            break

print(ans)