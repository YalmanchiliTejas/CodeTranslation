import sys
readline = sys.stdin.buffer.readline
def even(n): return 1 if n%2==0 else 0
n = int(readline())
s = readline().rstrip().decode('utf-8')
k = int(readline())

res = s[k-1]
ans = ""
for i in s:
    if i == res:
        ans += i
    else:
        ans += "*"
print(ans)