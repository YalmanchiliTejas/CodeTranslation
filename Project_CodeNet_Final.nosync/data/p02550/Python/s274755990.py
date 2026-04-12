import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

n, x, m = map(int, input().split())

ans = 0
f_ans = None
anses = []
for i in range(n):
    if f_ans is None:
        f_ans = x % m
    else:
        f_ans = (f_ans ** 2) % m
    if f_ans == 0:
        print(ans)
        sys.exit(0)
    if f_ans == 1:
        ans += (n - i)
        print(ans)
        sys.exit(0)
    if f_ans in anses:
        index = anses.index(f_ans)
        anses = anses[index:]
        ans += ((n - i) // len(anses)) * sum(anses)
        ans += sum(anses[:((n-i) % len(anses))])
        print(ans)
        sys.exit(0)
    anses.append(f_ans)
    ans += f_ans
print(ans)
