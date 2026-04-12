def comb(n, k):
    ans = 1
    for i in range(k):
        ans *= (n-i)
    for i in range(k):
        ans //= (k-i)
    return ans

def count(n, k):
    if len(n) < k:
        return 0
    if k == 0:
        return 1
    if int(n) == 0:
        return 0
    if n[0] == "0":
        return count(n[1:], k)
    return count(n[1:], k-1) + comb(len(n)-1, k)*9**(k) + (int(n[0])-1)*comb(len(n)-1, k-1)*9**(k-1)

n = input()
k = int(input())
print(count(n, k))