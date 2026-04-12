import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n = int(input())
a = list(map(int, input().split()))
s1 = 0
s2 = 0
M = 10**9+7
for item in a:
    s1 += item
    s2 += item**2
    s1 %= M
    s2 %= M
ans = (s1**2 - s2)*pow(2, M-2, M)
print(ans%M)