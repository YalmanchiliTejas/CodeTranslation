def l_in(type_): return list(map(type_, input().split()))
def i_in(): return int(input())
def m_in(type_): return map(type_, input().split())
def r_in(n, type_): return [type_(input()) for _ in range(n)]
const = 1000000007
ans = 0

n = i_in()
a = l_in(int)

ins = 0
for i in range(1, n):
    ins += a[i-1]
    ans += ins * a[i]

print(ans%const)
