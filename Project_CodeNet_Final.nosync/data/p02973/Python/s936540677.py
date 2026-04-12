import bisect

n = int(input())
# bisectが昇順のリストにしか対応していないのでマイナスをかける。
# -> ansの順序が昇順で管理できるようになる。最小値をans[-1]で管理する。
A = [- int(input()) for _ in range(n)]

ans = [A[0]]
for a in A[1:]:
  # ansの最小値以下の数値 -> append, else: a > ans[?] を満たす左端の?の値を書き換える。
  if a >= ans[-1]:
    ans.append(a)
  else:
    pos = bisect.bisect_right(ans, a) 
    ans[pos] = a 
print(len(ans))