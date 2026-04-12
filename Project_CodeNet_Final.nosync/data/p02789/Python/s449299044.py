import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n,m = map(int, input().split())
if n==m:
    ans = "Yes"
else:
    ans = "No"
print(ans)