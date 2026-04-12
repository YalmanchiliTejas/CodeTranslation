import sys

N, X, M = map(int, sys.stdin.readline().split())

def f(x, m):
    return x**2 % m

a = []
a.append(X)

exists = set()
exists.add(X)
ans = a[0]
for i in range(1, N):
    tmp = f(a[i-1], M)
    if tmp in exists:
        start = a.index(tmp)
        # print("start", start)
        break
    ans += tmp
    a.append(tmp)
    exists.add(tmp)
else:
    # ループ未満で終了する場合
    print(ans)
    sys.exit()

# print(a)
# print("ans", ans) 
 
before_score = sum(a[:start])
# print("before_score", before_score)

loop = a[start:]
# print(loop)
loop_score = sum(loop)
# print("loop_score", loop_score)
loop_n = len(loop)
N -= start
res_n = N % loop_n
print(before_score + loop_score * (N // loop_n) + sum(loop[:res_n]))